Getting Started
===============
This program specificaly in roman.cpp converts roman numerals to aribic numbers, 
and vice versa. Member functions are used to exsicute aspects of the main.cpp and
test files. GetInt() converts the stored roman numirals to aribic numbers, GetRoman()
will retreve the current roman numeral its stored as. SetRoman() can set both an
arabic number and a roman numeral to the stored number. IncreaseWith() adds the 
current number to a roman numeral passed as an argument. convertIntToRoman() converts
an aribic number to a roman numeral, and convertRomanToInt() converst a roman numeral
to an arabic number.

Installation and RUN
====================

1.) Put "make all" in the terminal to compile the program
2.) to run the main.cpp program input "./obj/roman" into terminal.
3.) To test the program input "make test" into the terminal
4.) to clear the doc and bin file input "make clean" into the terminal


Documentation
=============

To make the Doxyfile document the project input "make doc" into terminal. To 
access the documentation go to ./doc/index.html