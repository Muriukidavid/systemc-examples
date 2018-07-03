### The D Flip-flop

The D flip-flop uses the clock signal as the control signal.<br>
The flip-flop modelled here is sensitive to the positive edge of the clock.<br>
<b>Every time the clock is at the rising edge the input will be transmitted to the output of the flip flop</b><br>

### D Flip-Flop
<p align="left">
  <img src="img/dff.png" width="250"/>
</p>

### Truth Table
<p align="left">
  <img src="img/truthtable.png" width="250"/>
</p>

### Model of Computation
<p align="left">
  <img src="img/MoC.png" width="250"/>
</p>

### Timing Diagram
<p align="left">
  <img src="img/timingdiagram.png" width="250"/>
</p>

### D Flip-flop in detail
Logic gates have been combined to make a D flip-flop.<br>
Combine four nand gates and a single not gate.<br>
The image below illustrates the process.<br>
<p align="left">
  <img src="img/dffdetail.png" width="250"/>
</p>

### Four bit shift register
Shift Registers can be used to transfer data. They can also be used to switch between serial and parallel data .<br>
The data that at the input of the flip-flop is pushed to the next flip-flop's output on every clock cycle, the output of one flip-flop feeds the input of the following flip-flop.<br>
All of the flip-flops are driven by a single clock to syncronize them.
<br>

This is the depiction of the four bit register.
<p align="left">
  <img src="img/SIPO_4-bit_shift_reg.gif" width="250"/>
</p>

This is the timing diagram of the 4 bit shift register.
<p align="left">
  <img src="img/timingdiagramsr.png" width="250"/>
</p>
