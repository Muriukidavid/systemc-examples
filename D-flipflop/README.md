### The D Flip-flop

D flip-flop is a controlled Bi-stable latch where the clock signal is the control signal.<br>
They can either be positive edge triggered D flip flop or negative edge triggered D flip-flop.<br>
The clock has to be high for the inputs to get active.<br>
The D flip-flop modelled in here is triggered by the positive edge of the clock.It has input D and output Q.<br>

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
  <img src="img/dfftracediagram.png" width="250"/>
</p>

### Detailed D Flip-flop
The D Flip-flop is made of a combination of logic gates.<br>
One of the combinations is the use of four Nand Gates and a Not Gate.<br>
Its connection is as shown.<br>
<p align="left">
  <img src="img/dffgates.png" width="250"/>
</p>

### Four bit shift register
Shift Registers are sequential logic circuits, capable of storage and transfer of data.<br>
They load the data present on their inputs and then moves or “shifts” it to its output once every clock cycle.<br>
It consists of several D Flip-flop,one for each data bit connected together in serial.<br>
The output of one latch becomes input of the next latch.<br>
They are all driven by the same clock signal making them synchronous.<br>
The 4 bit shift register is as shown:
<p align="left">
  <img src="img/SIPO_4-bit_shift_reg.gif" width="250"/>
</p>

The timming diagram of the 4 bit shift register<br>
<p align="left">
  <img src="img/shiftreg.png" width="250"/>
</p>

###Conlusion
The 4-bit shift register was implemented successfully .<br>


