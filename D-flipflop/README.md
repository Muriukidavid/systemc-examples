### The D Flip-flop
A flip-flop is a device that has two stable states and is used to store state information.
The D flip-flop captures input D and sends it to output Q at the positive or negative edge of the clock.
The D flip-flop modelled in here is triggered by the positive edge of the clock.<br>

### D Flip-Flop
<p align="left">
  <img src="img/dff.png" width="250"/>
</p>

### Truth Table 
The truth table of a d flip-flop is as follows<br>
<p align="left">
  <img src="img/dfftt.png" width="250"/>
</p>

### Model of Computation
<p align="left">
  <img src="img/dffmoc.png" width="250"/>
</p>

### Timing Diagram
<p align="left">
  <img src="img/DffTimingdiagram.png" width="250"/>
</p>

### Detailed D Flip-flop
The D Flip-flop is made of a combination of logic gates. One of the combinations is the use of four Nand Gates and a Not Gate. The connections of the gates is as shown in the image below.<br>
<p align="left">
  <img src="img/dffgates.png" width="250"/>
</p>

### Four bit shift register
A simple Shift Register can be made using only D-type flip-Flops, one flip-Flop for each data bit. The output from each flip-Flop is connected to the D input of the flip-flop at its right. Shift registers hold the data in their memory which is moved or “shifted” to their required positions on each clock pulse.
The number of latches in a bit shift register depend on the number of bits to be stored.<br>

The 4 bit shift register looks as shown below
<p align="left">
  <img src="img/SIPO_4-bit_shift_reg.gif" width="250"/>
</p>

Model of Computation used to develop the shift register:
<p align="left">
  <img src="img/fourBSR.png" width="250"/>
</p>

The timming diagram of the 4 bit shift register is as follows
<p align="left">
  <img src="img/4bitShiftRegTimingDiagram.png" width="250"/>
</p>

