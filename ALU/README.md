### CONTRIBUTORS
1.I39/2486/2016 - Stephen Odhiambo - Research<br>
2.I39/1383/2015 - Ruth Mbugua - Research<br>
3.I39/2485/2016 - Hudson Lundi - Coding<br>
4.I39/2495/2016 - Evans Shango - Testing and Debugging<br> 
5.I39/2499/2016 - Bliss Maake - Report<br><br>


This is an ALU, which is a makefile project and so no need for an IDE. 
Just cd into the folder and run the command 'make'.<br><br>

### ALU(ARITHMETIC AND LOGIC UNIT)

An Arithmetic Logic Unit (ALU) is a combinational logic circuit that can perform different arithmetic and bitwise logical operations on integer binary numbers.<br>
It takes two inputs, called operands, and a code, called OPCODE, which specifies the operation to be performed on the operands.It also has the result/output which is the result of the operation on the operands.<br>
ALU may have Status signals on the output, which carry supplemental information about the results of the operation.e.g it can be a carry-out/borrow bit, zero bit, negative, and parity.<br>
Operands and results generated are normally read or stored in registers.<br>

ALU can be depicted as shown:
<p align="left">
  <img src="img/ALU.jpeg" width="300"/>
</p>

Operand1 and Operand2 are the inputs.

### OPERATIONS

ALUs perform the following operations:-<br>
Logical Operations that include AND, OR, NOT, XOR, NOR, NAND <br>
Arithmetic Operations:Bit addition and subtraction.<br>
Bit-Shifting Operations: This pertains to shifting the positions of the bits by a certain number of places to the right or left.<br>
This operations are defined by OPCODES and the OPCODES are then called as functions to manipulate the inputs and produce result <br>

The ALU modelled took two 4-bit numbers as inputs output results as:-<br><br>

• Sum of the two numbers.<br>
• Difference of the two numbers.<br>
• Increment of the first operand (OP1) by 1.<br>
• Decrement of the first operand (OP1) by 1.<br>
• Bit-wise AND of the two numbers.<br>
• Bit-wise OR of the two numbers.<br>
• Bit-wise NAND of the two numbers.<br>
• Bit-wise XOR of the two numbers<br><br>

The result output of the ALU consisted of one 4-bit result (RESULT), a carry/borrow bit (CARRY) and a zero bit (ZERO).<br>

The OPCODE Table of the operations are as shown:-<br>

<p align="left">
  <img src="img/OPCODETable.jpeg" width="400"/>
</p>

### RESULTS

The ALU was implemented in systemc and the following output found from traced signals.<br>

Traced signals timing diagram:
<p align="left">
  <img src="img/timing_diagram.png" width="700"/>
<p>

### CONCLUSION
The 4-bit ALU with functionalities mentioned in the OPCODE was implemented successfully.

