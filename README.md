# 22re Tachometer driver board

#### A tachometer driver board for a 1st gen 4runner and 22re, using a signal from the negative terminal.

With the orginal ICs that Toyota used for their tachometer being out of production, the only options to fix a 1st gen 4runner's tachometer is to design a new board around a new style of frequency to voltage IC, or a micro controller. The latter was chosen for this project, using an Attiny85 as the meter that Toyota made for the 1st gen 4runner is not very linear, and Attiny85 is more flexible than a LM2917N. This code and board design should work for any voltage based meters driven by some sort of frequency.

The board only needs 3 inputs: power, ground, and a frequency input that corresponds with engine rpm. It was designed around receiving a signal from the coil negitive pin, so the resitor values to the optocoupler likely will need to change if a different input method is chosen.

The board has provisions for a dip switch to change cylinder counts (As in the case of an engine swap), as the common 5vz and 3rz engine swaps send the tachometer a different frequency than a 22r. 

The current issues with the code and board are: The meter doesn't fall back to the proper rpm after revving the engine(I believe it's due to wear of the needle rod, as tapping the dash fixes it), and the code only reads every other pulse gap that it sees.
