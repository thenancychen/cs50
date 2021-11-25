#include <stdio.h>
#include <cs50.h>

int main(void)

{
    string name = get_string("What is your name? "); //asks the user what their name is
    printf("hello, %s\n", name); //prints hello, user's name

}