Board type A is the only tested board that can be verified to work, board type B has not been tested, and capacitor and resistor values for it's filter will need to be chosen. The rest of the doc will be on board type A unless specified.



The board is designed to directly replace the OEM board, reusing it's mounts to be a bolt in replacement. The old mounts/ input terminals will need to have their rivets removed and resoldered to the new board.



The optocoupler used is a LY319, as i had a few laying around, and they are faster than an PC817. A PC817 should be a fine replacement, as both optos have the same pinouts (this has not be verified). 



The values to components that won't need to be changed are written on the board, the others are labeled in order to be cross refenced. 

1. LR1 - 0 Ohms
2. LR1\_1 - 0 Ohms
3. LR1\_2 - 1000 Ohms
4. LR1\_3 - 22K Ohms
5. LR1\_4 - 33k or 4.7K Ohms - If connected to a factory tachometer signal on a 22re (maybe 22r?) use the second value.
6. Z5U - 0.1 uF
7. K220J - Dnp



The potentiometer is a Bourns 3362P, 100 Ohm. Set the side going to the meter around 20 ohms.



The clock circuit is not needed, and can be repurposed to a shift light output. 



The CYL dip switch is a generic 1 gang 2.54mm pitch switch, which is not needed if the cylinder change function in the code is not used. 

