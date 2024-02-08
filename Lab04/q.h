//@file q.h
//@author Bryan Lee Kwan Hong (Kwanhong.lee)
//@course CSD1121F22
//@section Section A
//@tutorial Lab 4
//@date 23/9/2022
//@brief This is the header file for q.h and qdriver.c that declares the functions tile, and dispense_change

//function break down is the function that does the calculation and gets a new remainder. This is just declaring that function.

void break_down(int cents);

//function go is a function that takes in nothing and returns a value int. It serves as a call so it wont be an implicit function.
int go(void);

//function print line declaration is so that q.c knows what print line is
void print_line(int index, int rest, int denomination);