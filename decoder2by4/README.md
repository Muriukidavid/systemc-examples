This is a 2-by-4 decoder, which is a makefile project and so no need for an IDE. 
When the terminal is located in the working directory, running the following command accomplishes all the work. 

    make decoder


A line decoder is a device that changes the input code into a set of signals.<br>
It takes n-digit binary number and decodes it into 2<sup>n</sup> data lines, the reverse of encoding. <br>
In the following truth table, only the output OUT1 is high when the inputs are low(0). The output Out2 is high when the input In_a is low(0) and In_b is high(1). The output Out3 is high when the input In_a is high and In_b is low. The output Out4 is high when the input In_a is high and In_b is high.It decodes a two digit binary number.
Only one signal is high(selected) when the right binary numbers are available on the inputs. <br>

### Truth table: 
<p align="left">
  <img src="images/TruthTable.png" width="250"/>
</p>

### Circuit:
<p align="left">
  <img src="images/circuit.png" width="200"/>
</p>

### Model of computation:
<p align="left">
  <img src="images/decoder 2by4.png" width="400"/>
</p>
The internal models of the 2-by-4 decoder are modeled as follows:
<p align="left">
  <img src="images/insidedecoder2by4.png" width="400"/>
</p>

### Results:
The above model of computation(MOC) was implemented using systemc (accompanying this document) and the following output found from traced signals.<br>
Traced signals timing diagram:
<p align="left">
  <img src="images/GTKwave.png" width="400"/>
<p>

### Conclusion:
By running a single command,
  make decode
the files are compiled without errors and the required behaviour of the code exhibited.