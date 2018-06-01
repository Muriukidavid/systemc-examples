A 2by4 line decoder is a system that takes in 2 inputs and passes it across logic gates and produces 4 ouputs. The output is always HIGH at any time after being passed across the combinational gates.

This is modification of the 1 to 2 line decoder with 2 more submodules. The level of abstraction has dropped further to model the the behaviour of the 1 to 2 line decoder with the circuit shown below:
Therefore 2 new classes and_gate and inverter are introduced to model the above functionality.
 
### Circuit:
<p align="left">
  <img src="images/2by4DecoderCircuit.jpg" width="200"/>
</p>

The truth table  is as shown below:

<p align="left">
  <img src="images/truthtable.jpg" width="250"/>
</p>

The MOC of the reimplemented 1 t0 2 line decoder module is as shown below

### Model of computation:
<p align="left">
  <img src="images/moc.jpg" width="400"/>
</p>

### Results:
The above MOC was implemented in systemc (code in this folder) and the following output found from traced signals.<br>
Traced signals timing diagram:

<p align="left">
  <img src="images/timingdiagram.png" width="400"/>
<p>

