Loads a Turing Machine from a text file, then requests info about the turing machine and an input.
Simulates k-tape machines. This simulator is closely tied with the Flattener project.

A valid Turing machine text file is of the form

 
name: <string_name>
   
init: <state>
   
accept: <state>
   

// Then one or more of the following Transition Function Form.
<Domain_State>, [<Domain_Input>, ...]
 
<Range_State>, [<Range_Output>, ...], [<Head_Moves>, ...]


See Run-Time prompt for input description.