**Choosing a board to build**

Board type A is a more basic board, off loading more noise filtering to the Attiny85, while Board type B does more input filtering. (Reference warnings)



**Building Notes**

When assembling either board, make sure that ICs are orientated in the correct direction. Harvest the old PCB mounts off of the OG tach board by drilling out the rivets and desoldering them. Resolder them on the new board and if wanted, rerivet or bolt them to the PCB. To remove the old board from the meter, gently break the old pins and push clips by slowly bending the clip back and forth to fatigue it. Replace them with the m3 bolts and nuts when installing the new board. Unsolder the meter's power wires, making note of which one is M+ and M-. M+ should be red, but double check. If uncertain, apply a small amount of power in either direction, like 3mA to verify polarity. I don't recommend this unless you have completely forgotten the correct polarity. If the tachometer doesn't work after it's put together and the Attiny85 has been programmed, try a different version of the code and verify that the Attiny's input leg is reviving a coil signal.



**Programming**

You will have to download 2 libraries for this to function, **MultiMap** by ROb Tillaart and **PinChangeInterrupt** by NicoHood. Then lookup a tutorial on how to program Attinys. I really liked this one, [https://homemadehardware.com/guides/programming-an-attiny85/](https://homemadehardware.com/guides/programming-an-attiny85/), it was really easy for me to follow. Other than that, program and install the Attiny into the socket.



**BOM for board type A V1.0**

1 ATTINY85-20PU					//Brains

1 8 pos, 2 row Dip socket, 2.54 mm x 7.62 mm	//To make Brains programmable.

1 7805, TO-220-3				//5v regulator

1 2N2222A, TO-92-3				//Transistor for Brains protection

1 PC817 or LY319, DIP-4				//More Brains input protection

1 74AHC, SOT-23-5				//Dirty input to square

1 100 Ohm Bourns 3362P				//Precise Meter tuning

2 1N4935G, DO-41 				//Reverse polarity protection

2 Long 3m bolts and nuts



I used TE Connectivity LR1 resistors because they were cheap, but any 1/2w axial through hole resistor should work.

1 1k Ohm

2 10k Ohm

1 50 Ohm

2 0-2 Ohm resistors, as low as possible, jumpers will also work.

1 200 Ohm

1 22K Ohm

1 33k or 4.7k Ohm, 4.7k if using factory tach pin, 33k if not.



All caps have 2.5mm lead spacing

1 0.1uF, leaded ceramic

2 0.1uF, 0805 SMD ceramic

2 10uF, leaded electrolytic



Optional clock / install if more accuracy is wanted

2 22pF, leaded ceramic caps 

1 16Mhz HC-49 leaded



Optional CYL circuit

1 1k Ohm

1 1 pole dip switch, DS04



**Warnings and Notes.**

This board should be used after you have verified that the original IC on the factory board died. Before buying all the parts, verify that gauge's input pins have a clean ground, coil neg signal, and 12+ volts. Check solder joints and inspect for broken parts. This board **WILL NOT** magically fix worn out needles, don't expect it to miraculously fix your a million mile tach. It is designed to replace the old IC with a new one. 



The board and code should work this any meter driven by rising voltage, but it has only been tested on a 1st gen 4runner tachometer, and 5$ Amazon mA meter.



Board Type B was a backup in case the simpler Board Type A wouldn't work. It is untested, use at your own risk.

Check the schematic for component values.



Most component values have been written into the board's solder mask, but the ones that haven't are ones that affect filtering the incoming coil signal and are likely to be board specific. These values are liable to be changed at any time.



LR1 - 0 Ohms

LR1\_1 - 0 Ohms

LR1\_2 - 1000 Ohms

LR1\_3 - 22K Ohms

LR1\_4 - 33k or 4.7K Ohms - If connected to a factory tachometer signal on a 22re (maybe 22r?) use the second value.

Z5U - 0.1 to 0.22uF

K220J - Dnp



