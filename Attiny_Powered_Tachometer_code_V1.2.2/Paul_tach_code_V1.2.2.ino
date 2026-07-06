/*
V1.2.2

Tachometer code for dirty coil negitive signal
This code measures the time it takes for the coil to fire, measuring the time between the each coil dewll ending.
It assumes that the incoming signal only goes high (or low) when the coil is fired, not when dwell starts.
It will attempt to ignore bounces at the end of the spark, by triggering a timer that will not let the rpm be calculated until the signal stays low for a set time.

There are provisions for being able to flip a dip switch and have the tachometer be setup for a new cylinder count.

Written 6/2026
Paul Dueck

*/
#include "MultiMap.h"
#include "PinChangeInterrupt.h"
const int COIL = 2;       //Coil input      Attiny85 = 2
const int tach_out = 1;  //Meter signal    Attiny85 = 1
const int cyl_in = 0;     //Engine swap pin Attiny85 = 0

bool coil_hap;
volatile bool allow_count;
bool first;
volatile unsigned long mycros;
// Set min_time_down to be just smaller in porportion to rpm
// If redline == 5000, set to around 3000, red == 8000, set to around 1500.
const long min_time_down = 2500;  //Time (in micros) before a pulse length is accepted
unsigned long min_micros;
const long time_out = 500;  //Time before rpm gets set to 0 after COIL_sense stops seeing pulses
unsigned long time_out_millis;
unsigned long coil_high_first;
unsigned long coil_high_second;
unsigned long avgpulse;  // Average Rpm
float correction = 2.2;  // Variable to correct pulse_time
//4 stroke = 2.2, 2 stroke = 1.1?
int cyl = 4;  // Amount of cylinders the motor has
//If engine swap is not in the plans, set cyl_new to be the same as cyl manually
int cyl_new = 6;  // Amount of cylinders a swap motor would have

// Lookup table
float array_rpm[] = { 0, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000 };  // Lookup Rpm
float array_PWM[] = { 0, 30, 40, 72, 102, 130, 154, 180, 204, 228, 255 };              // Lookup PWM
// Generate by looking at serial out, reading and comparing Rpm, tach_out to a known input signal frequency
// Meter specific
// 255 should equal the max range of motion that the meter has
int size = 11;  // Amount of values stored in one table


void setup() {
  pinMode(cyl_in, INPUT);
  pinMode(COIL, INPUT_PULLUP);
  pinMode(tach_out, OUTPUT);
  attachPCINT(digitalPinToPCINT(COIL), COIL_sense, CHANGE);
  digitalWrite(tach_out, LOW);
  delay(100);  // Let the Arduino settle before work

  // Engine swap code
  if (digitalRead(cyl_in) > 0) {
    cyl = cyl_new;
  }
}

void loop() {
  volatile unsigned long coil_high1;
  volatile unsigned long coil_high2;
  unsigned long pulse_time;
  int rpm;         // Generated Rpm by measuring pulseIn

  //Timeout if no new signals
  if (millis() - time_out_millis >= time_out) {
    coil_high1 = 0;
    coil_high2 = 0;
    avgpulse = 0;
  }
  //Only trigger if isr lets it
  if (allow_count == 1) {
    disablePinChangeInterrupt(COIL);
    coil_high1 = coil_high_first;
    coil_high2 = coil_high_second;
    pulse_time = coil_high2 - coil_high1;
    avgpulse = runAvg(avgpulse, pulse_time);
    //If it wants to be stupid, ignore it.
    if (avgpulse > 1000000) {
      return;
    }
    enablePinChangeInterrupt(COIL);
    allow_count = 0;
  }
  //Time to RPM
  rpm = correction * 60.0 * (1000000.0 / (avgpulse * cyl));
  // Interpolation
 float tach_PWM = multiMap<float>(rpm, array_rpm, array_PWM, size);
  //If for some reason PWM wishes to wrap, well NO.
  if (tach_PWM > 255) {
    analogWrite(tach_out, 255);
  } else {
    analogWrite(tach_out, tach_PWM);
  }
}


void COIL_sense() {
  mycros = micros();
  coil_hap = digitalRead(COIL);
  if (coil_hap == 1 && mycros - min_micros >= min_time_down) {  //Measuring time between 2 pulses
    if (first == 0) {
      coil_high_first = mycros;
      first = 1;

    } else if (first == 1) {
      coil_high_second = mycros;
      allow_count = 1;
      first = 0;
    }
    time_out_millis = millis();  //Timeout function
  }
  min_micros = mycros;  //Reset "allow" timer
}

//Average rpm calculator
unsigned long runAvg(unsigned long avg, unsigned long n) {
  return avg = (avg * 1 + n) / 2;
}