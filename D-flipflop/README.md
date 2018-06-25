### THE D-FLIP-FLOP:

A D-Flipflop, also known as a "data" or "delay" flip-flop captures the value of the D-input at a definite portion of the clock cycle (such as the rising edge of the clock).<br> That captured value becomes the Q output. At other times, the output Q does not change.<br> The D flip-flop can be viewed as a memory cell, a zero-order hold, or a delay line.<br>
<p align="left">
  <img src="images/dff.png" width="300"/>
</p>


### Truth Table:
Below is a D-Flipflop truth table:
<p align="left">
  <img src="images/truth_table.png" width="300"/>
</p>

### Circuit:
<p align="left">
  <img src="images/circuit.png" width="500"/>
</p>

### Model of computation:
A Model of computation for the D_Flipflop is as shown below:
<p align="left">
  <img src="images/moc.PNG" width="500"/>
</p>

### THE 4-BIT SHIFT REGISTER:

<p>A shift register (Serial-In Parallel-Out type) consists of a group of flip-flops arranged such that the output of one feeds the input of the next such that the binary numbers stored, shift from one flip-flop to the next controlled by a clock pulse. For a 4-bit shift register utilising the d-type flip-flops, the clock inputs of all the flip-flops connect to a common line, hence they receive clock inputs simultaneously. With a d-type flip-flop, the value at the input D transfers to the output Q on the rising edge of every clock pulse. Since they all receive the clock pulse simultaneously, they all do this operation together on the rising edge.</p>

Below is an implemantation of a 4-bit shift register

<p align="left">
  <img src="images/SIPO_4-bit_shift_reg.gif" width="450"/>
</p>

A truth table representing a 4-bit shift register is as shown below

<p align="left">
  <img src="images/4bit_truth_table.png" width="400"/>
</p>

### Results:
The above Mod Of Computation of a D-Flipflop was implemented in systemc and the following output found from the traced signals.<br>
Traced signals timing diagram:
<p align="left">
  <img src="images/timing_diagram.png" width="400"/>
<p>

Below is a timing diagram of a 4-bit shift register
<p align="left">
  <img src="images/4bit_shift_reg.png" width="500"/>
</p>

### Conclusions:
Applications of a D-Flipflop include;<br>
<p>Edge triggered D flip flops are used in the sampling circuits to sample the date at particular time interval. i.e. at a sharp interval when the clock changes from low to high the input data will be delivered to the output and it remains the same until the next clock low to high. We can adjust the sampling intervals by changing the clock pulse widths.</p>
A D-Flipflop is used as a buffer to store the intermediate data.
It is also used to introduce the delay in the circuits.

A D-Flipflop was thus implemented using four instances of a NAND gate and an instance of a NOT gate.<br>

On the other hand, registers are used in digital electronic devices like computers as;
Temporary data storage<br>
Data transfer<br>
Data manipulation<br>
As counters.<br>

The main application of Serial in Parallel Out(SIPO) shift register is to convert serial data into parallel data. Hence they are used in communication lines where demultiplexing of a data line into several parallel line is required.

