//@file q.c
//@author Bryan Lee Kwan Hong (Kwanhong.lee)
//@course CSD1121F22
//@section Section A
//@tutorial Lab 04
//@date 23/9/2022
//@brief This q.c file includes task 1 and task 2 or lab 4, taking input as dollars.cents

#include <stdio.h> //printf, scanf
#include "q.h"

//This function prints the columns and justifys them to fit the required format. This print line takes the remainder divided by the denomination to give number
// or COUNT of the bill. This adds on to the index, and applies the denomination, and also produces the count of the require dbill.
void print_line(int index, int rest, int denomination)
{
    int count = 0;
    count=rest/denomination;
    printf("| %-2d | %12.2f |     %d |\n", index + 1, denomination/100.0, count); 
}

//This function prints out the required lines and words, and places the values out on a array. Initialising the array to 0 will allow it to
// go all the way to the last unit in the array as the last digit is 11. When it loops, it will call print line with their given inputs. 
// this will also peform a modulo loop will takes the remainder until is 0. This calls go so it can repeat the process.
void break_down(int cents)
{
    printf("\n+----+--------------+-------+\n");
    printf("| #  | Denomination | Count |\n");
    printf("+----+--------------+-------+\n");
    int Billtypes [] = {10000,5000,1000,500,200,100,50,20,10,5,1};
    int i = 0;
    while (i != 11)
    {
        print_line(i, cents, Billtypes[i]);
        cents = cents%Billtypes[i];
        i++;
    }
    printf("+----+--------------+-------+\n"); 
    go();
}

// This function takes the users input in dollar and cents, and then the console will read the values. If the value is not in the correct format
// the compiler will see if the parameters matches the format given. If not, it will print not correct format.
// If the value given is negative, then it will prompt for a non-negative input.
// If the given fomrat is not a value between 0 and 99, then it will prompt for a value that fits 0 to 9.
// Once it recognises that everything is in the correct format, then it will convert the value given in cents format so that it can be broken down
// into the correct denominations. This goes to break down.
int go(void)
{
    printf("Please enter total value: ");
    int dollars, Rcents;
    int validate = scanf("%d.%d", &dollars, &Rcents);
    if (validate != 2)
    {
        printf("Program ended\n");
    } else if (dollars < 0) {
        printf("Program ended\n");
    } else if (Rcents <0 || Rcents > 99)
    {
        printf("Program ended\n");
    } else {
    int cents = (dollars*100)+Rcents;
    break_down(cents);
    }
    return 0;
}