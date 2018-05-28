This is a 2-by-4 decoder example, which is a makefile project and so no need for an IDE. 
Just cd into this folder and run the command 

    make decoder


A line decoder is a device that changes the input code into a set of signals.<br>
It takes an n-digit binary number and decodes it into 2<sup>n</sup> data lines.
It does the reverse of encoding. <br>
In the following truth table, only the output OUT1 is high when the inputs are zero. The output Out2 is high when the input In_a is 0 and In_b is 1. The output Out3 is high when the input In_a is 1 and In_b is 0. The output Out4 is high when the input In_a is 1 and In_b is 1.It decodes a two digit binary number.
Only one signal is high(selected) when the right binary numbers are available on the inputs. <br>
Its truth table: 
<p align="left">
  <img src="images/TruthTable.png" width="250"/>
</p>

### Model of computation:
<p align="left">
  <img src="images/decoder 2by4.png" width="400"/>
</p>

### Results:
The above MOC was implemented in systemc (code in this folder) and the following output found from traced signals.<br>
Traced signals timing diagram:
<p align="left">
  <img src="images/GTKWave.png" width="400"/>
<p>

