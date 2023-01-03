#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//function prototypes
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //get user input
    string Input;
    Input = get_string("Text: ");

    //calculate letters, words and sentences
    float letters = count_letters(Input);
    float words = count_words(Input);
    float sentences = count_sentences(Input);

    //implementing the Coleman-Liau index
    float L = (letters / words) * 100;
    float S = (sentences / words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int i = round(index);

//print out the appropriate grade
    if (i > 16)
    {
        printf("Grade 16+\n");
    }
    else if (i < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", i);
    }
}

//count the number of letters
int count_letters(string text)
{
    int letters = strlen(text);
    int count = 0;

    for (int i = 0; i < letters; i++)
    {
        char c = text[i];
        if (isalpha(c) != false)
        {
            count++;
        }
    }
    return count;
}

// count the number of words
int count_words(string text)
{
    int words = strlen(text);
    int count = 1;

    for (int i = 0; i < words; i++)
    {
        char c = text[i];
        if (c == ' ')
        {
            count++;
        }
    }
    return count;
}

//count the number of sentences
int count_sentences(string text)
{
    int sentences = strlen(text);
    int count = 0;

    for (int i = 0; i < sentences; i++)
    {
        char c = text[i];
        if (c == '.' || c == '!' || c == '?')
        {
            count++;
        }
    }
    return count++;
}

