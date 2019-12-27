This is our assembly.

**ALERT! THIS PROJECT ISN'T STILL FINISHED**

To run your application in our assembly change the program.oa file to your program, then compile main.cpp in any way you like and run it in the same folder as program.oa. We compile it using g++, that's why you can see a.out in the folder.



#DOCUMENTATION



Here you will find all the commands in our assembly


Arguments:


{value} - specified in the command's description

{location} - index in memory with an ampersand before it. For example &0 refers to the first memory cell, and &126 to 127th.


Working commands:


SET {value} {location} - sets {value} (int) to {location}

ADD {value} {location} - adds {value} (int) to {location}

MULT {value} {location} - multiplies {locaton} by {value} (int)

DIV {value} {location} - DIV {locaton} by {value} (int) (leaves only the whole part)


More commands coming soon...
