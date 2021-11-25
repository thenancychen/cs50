#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string user_input);
int count_words(string user_input);
int count_sentences(string user_input);

int main(void)
{
    //take user input 
    string user_input = get_string("Text: "); 
    int letters = count_letters(user_input);
    int words = count_words(user_input);
    int sentences = count_sentences(user_input);

    //letter average
    float l = (((float) letters / words) * 100); 
    //sentence average
    float s = (((float) sentences / words) * 100); 
    int index = round(0.0588 * l - 0.296 * s - 15.8);

    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else 
    {
        printf("Grade %i\n", index);
    }
}

//counting how many letters are in the text
int count_letters(string text) 
{
    int count = 0;
    int len = strlen(text);
    //irerates through each letter, counts 1 for each letter
    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            count += 1;
        }
    }
    return count;
}

//counts how many words by looking at spaces and then adding 1
int count_words(string text) 
{
    int count = 1;
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (text[i] == ' ')
        {
            count += 1;
        }
    }
    return count;
}

//counts how many sentences based on punctuation
int count_sentences(string text) 
{
    int count = 0;
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            count += 1;
        }
    }
    return count;
}