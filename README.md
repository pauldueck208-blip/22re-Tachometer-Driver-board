The tachometer that I had died, and doing some investigation the original Toshiba IC had died. With them being out of production, the only options were to design a new board around a new frequency to voltage chip, or a micro controller. I chose the latter, picking an Attiny85 and as the meter that Toyota made for the 1st gen 4runner is not very linear. This code and board design should work for any voltage based meters driven by some sort of frequency.

The board only needs 3 inputs: power, ground, and a frequency input that corresponds with engine rpm. It was designed around receiving a signal from the coil negitive pin, so the resitor values to the optocoupler likely will need to change if a different input method is chosen.

The board has provisions for a dip switch to change cylinder counts (As in the case of an engine swap), as the common 5vz and 3rz engine swaps send the tachometer a different frequency than a 22r. 

The current issues with the code and board are: The meter moves in steps when it should move smoothly, and the code only reads every other pulse gap that it sees.
