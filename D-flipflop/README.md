ABALLA SAMUEL OTIENO
I39/2498/2016
### THE D-FLIP-FLOP:

A D-Flipflop, also known as a "data" or "delay" flip-flop captures the value of the D-input at a definite portion of the clock cycle (such as the rising edge of the clock).<br> That captured value becomes the Q output. At other times, the output Q does not change.<br> The D flip-flop can be viewed as a memory cell, a zero-order hold, or a delay line.<br>
<p align="left">
  <img src="images/dff.png" width="250"/>
</p>


### Truth Table:
Below is a D-Flipflop truth table:
<p align="left">
  <img src="images/truth_table.png" width="250"/>
</p>

### Circuit:
<p align="left">
  <img src="images/circuit.png" width="200"/>
</p>

### Model of computation:
A Model of computation for the D_Flipflop is as shown below:
<p align="left">
  <img src="images/moc.PNG" width="400"/>
</p>

### Results:
The above Mod Of Computation was implemented in systemc and the following output found from the traced signals.<br>
Traced signals timing diagram:
<p align="left">
  <img src="images/timing_diagram.png" width="400"/>
<p>

### Conclusions:
Applications of a D-Flipflop include;<br>
<p>Edge triggered D flip flops are used in the sampling circuits to sample the date at particular time interval. i.e. at a sharp interval when the clock changes from low to high the input data will be delivered to the output and it remains the same until the next clock low to high. We can adjust the sampling intervals by changing the clock pulse widths.</p>
<p>It is used as a buffer to store the intermediate data</p>
<p>It is also used to introduce the delay in the circuits.</p>
A D-Flipflop was thus implemented using four instances of a NAND gate and an instance of a NOT gate.
