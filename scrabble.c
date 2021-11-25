#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    
    if (score1 > score2)
    {
        printf("Player 1 wins!\n"); 
    }

    else if (score1 < score2)
    {
        printf("Player 2 wins!\n"); 
    }
    else 
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    for (int i = 0, word_total = 0, len = strlen(word); i < len; i++) //for loop going through each index

    word_total = 0
    for i in range(0, len(word)):
        if islower(word[i])):
            word_total += POINTS[(word[i] - 97)]
        elif isupper(word[i])):
            word_total += POINTS[(word[i] - 65)]
    return word_total

    {
        if (islower(word[i])) //calculates lowercase letters
        {
            word_total += POINTS[(word[i] - 97)];
        }
        else if (isupper(word[i])) //calculates uppercase letters
        {
            word_total += POINTS[(word[i] - 65)];
        }
    }
    return word_total;

}
