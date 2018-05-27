A 2 to 4 line decoder is a 4 output logic circuit that takes 2 inputs. At any point in time, according to the combination of the input signals, there can only be 1 output signal that is HIGH. 

As a decoder, The circuit is shown below:
 
### Circuit:
<p align="left">
  <img src="images/2-to-4-Decoder-Circuit.jpg" width="200"/>
</p>

The truth table of the above circuit is as shown below:

<p align="left">
  <img src="images/truth-table.jpg" width="250"/>
</p>

The MOC of the above circuit is also shown below:

### Model of computation:
<p align="left">
  <img src="images/moc.png" width="400"/>
</p>

### Results:
The above MOC was implemented in systemc (code in this folder) and the following output found from traced signals.<br>
Traced signals timing diagram:

<p align="left">
  <img src="images/result1.png" width="400"/>
<p>


