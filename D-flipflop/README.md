### The D Flip-flop

The D flip-flop is a Bi-stable latch that uses the clock signal as the control signal.<br>
The D flip-flop modelled here is sensitive to the positive/ rising edge of the clock.<b>
The input will be transmitted to the output of the flip-flop everytime the clock is at the rising edge.<br>

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
Logic gates can be combined to make a D flip-flop.<br>
Combine four nand gates and a single not gate.<br>
The image below shows how this can be acheived.<br>
<p align="left">
  <img src="img/dffdetail.png" width="250"/>
</p>

### Four bit shift register
Shift Registers can be used to transfer data or swith between serial and parallel data .<br>
With every clock cycle, the data that was at the input of the flip-flop is pushed to the next flip-flop's input, that is, the output of one flip-flop feeds the input of the following flip-flop.<br>
A single clock drives all of the flip-flops in order to synchronize them.<br>
Below is the depiction of the four bit register.
<p align="left">
  <img src="img/SIPO_4-bit_shift_reg.gif" width="250"/>
</p>

Below is the timing diagram of the 4 bit shift register. 
<p align="left">
  <img src="img/timingdiagramsr.png" width="250"/>
</p>
