#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    //checks if argc is greater than 2
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //goes through length of the first index of argv to check if it is a digit
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //turns argv[1] to int, to plug into rotate function
    int k = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");

    //goes through length of plaintext and runs rotate function
    int length = strlen(plaintext);
    for (int i = 0; i < length; i ++)
    {
        plaintext[i] = rotate(plaintext[i], k);
    }
    printf("ciphertext: %s\n", plaintext);

}

//checks if string s is a digit
bool only_digits(string s)
{
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

//encipher plaintext, takes char c and moves by int n
char rotate(char c, int n)
{
    //if character is lower case
    if (islower(c))
    {
        c -= 97;
        c += n;
        c %= 26;
        return c += 97;
    }

    //if character is upper case 
    else if (isupper(c))
    {
        c -= 65;
        c += n;
        c %= 26;
        return c += 65;
    }

    //if puncutation
    else
    {
        return c;
    }
}
