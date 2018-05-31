This is a 2-by-4 decoder example, which is a makefile project and so no need for an IDE.
Just cd into this folder and run the command

    make decoder


A line decoder is a device that changes the input code into a set of signals.<br>
It takes an n-digit binary number and decodes it into 2<sup>n</sup> data lines.
It does the reverse of encoding. <br>

Below is a 2by4 decoder truth table:
<p align="left">
  <img src="images/truth_table.png" width="250"/>
</p>

###Circuit:
<p align="left">
  <img src="images/circuit.gif" width="200"/>
</p>

###Model of computation:
<p align="left">
  <img src="images/MoC.png" width="400"/>
</p>
A Model of computation of a 2by4 decoder using 4 AND gates and two 1by2 decoders:
<p align="left">
  <img src="images/moc.png" width="400"/>
</p>
###Results:
The above Mod Of Computation was implemented in systemc and the following output found from the traced signals.<br>
Traced signals timing diagram:
<p align="left">
  <img src="images/timing_diagram2.png" width="400"/>
<p>
###Conclusion:
A 2by4 decoder was implemented using two instances of a 1by2 decoder and 4 AND gates.
