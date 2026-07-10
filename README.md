# 22re Tachometer driver board

#### A tachometer driver board for a 1st gen 4runner and 22re, using a signal from the negative terminal.

With the orginal ICs that Toyota used for their tachometer being out of production, the only options to fix a 1st gen 4runner's tachometer is to design a new board around a new style of frequency to voltage IC, or a micro controller. The latter was chosen for this project, using an Attiny85 as the meter that Toyota made for the 1st gen 4runner is not very linear, and Attiny85 is more flexible than a LM2917N. This code and board design should work for any voltage based meters driven by some sort of frequency.
![Attiny Board Front](https://github.com/pauldueck208-blip/22re-Tachometer-Driver-board/blob/main/Images/Screenshot%202026-07-05%20162843.png)
The board only needs 3 inputs: power, ground, and a frequency input that corresponds with engine rpm. It was designed around receiving a signal from the coil negitive pin, so the resitor values to the optocoupler likely will need to change if a different input method is chosen.

The board has provisions for a dip switch to change cylinder counts (As in the case of an engine swap), as the common 5vz and 3rz engine swaps send the tachometer a different frequency than a 22r. 

Known issues with code V1.2: The code only reads every other pulse gap that it sees, the needle will occasionally jump up a bit and then fall back to the proper RPM, and if the board has been receiving power for a short time and then the engine of the tachometer is started, the needle will bounce to the end of it's travel and then go back to where it's supposed to be.

Acknowledgments: Jerry-Hat-Trick for board design, stitech and alto777 for coding.
