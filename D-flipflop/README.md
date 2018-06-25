### The D Flip-flop
A flip-flop is a device that has two stable states and is used to store state information.
The D flip-flop captures input D and sends it to output Q at the positive or negative edge of the clock .
The D flip-flop modelled in here is triggered by the positive edge of the clock.<br>

### D Flip-Flop
<p align="left">
  <img src="img/dff.png" width="320"/>
</p>

### Truth Table 
The truth table of a d flip-flop is as follows<br>
<p align="left">
  <img src="img/dfftd.png" width="320"/>
</p>

### model of computation of a d flip flop
<p align="left">
  <img src="img/dffmod.png" width="320"/>
</p>

### Timing Diagram
<p align="left">
  <img src="img/dfftracediagram.png" width="320"/>
</p>

### Detailed D Flip-flop
The D Flip-flop is made of a combination of logic gates. One of the combinations is the use of four Nand Gates and a Not Gate. The connections of the gates is as shown in the image below.<br>
<p align="left">
  <img src="img/dffgates.png" width="320"/>
</p>

### 4-bit shift register
The bit shift register moves data sequentially from intput to output once every clock cycle.
A bit shift register consists of D Flip-flop connected together. 
The output of one latch is connected to the input of the next latch.
They are all driven by the same clock signal making them synchronous.
They are used for storage or movement of data.
The number of latches in a bit shift register depend on the number of bits to be stored.<br>

The 4-bit shift register representation
<p align="left">
  <img src="img/SIPO_4-bit_shift_reg.gif" width="320"/>
</p>

The timming diagram of the 4-bit shift register is as follows:
<p align="left">
  <img src="img/shifttd.png" width="320"/>
</p>

