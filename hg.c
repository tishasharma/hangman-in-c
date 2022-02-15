#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int rmatches(char, char[], char[]);
void encrypt(char [], char[]);
int main()
{
    char unknown[80];
    char letter;
    int wguess = 0;
    int maxtries = 5;
    char word[80];
    int choice;
    int n;

    char words1[][80] = {"LUDO","TENET","MALANG","DHOOM","FANAA","SAAHO","WAR"};
    char words2[][80]={"WALLE","COCO","JAWS","SHREK","BOLT","KILLBILL","EASYA"};
    char words3[][80]={"GROOT","THOR","WANDA","WASP","GAMORA","LOKI","HELA"};
        
    /* welcome the user and show rules */
    printf("\n\nWelcome to Hangman!Guess the word!");
    printf("\n\nEach letter is represented by a *.");
    printf("\n\nYou have to type one letter in each try");
    printf("\n\nYou have %d tries to guess the word.", maxtries);
    printf("Enter 1 to choose Hindi movie category, 2 for English movie , 3 for Marvel character");
    scanf("%d",&choice);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    switch(choice)
    {
        
        case 1:
        {
        /* choose and copy a word from array of strings randomly */
        srand(time(NULL));
        n = rand() % 7;
        strcpy( word, words1[n]);
        }
        break;
        case 2:
        {
        /* choose and copy a word from array of strings randomly */
        srand(time(NULL));
         n = rand() % 7;
        strcpy(word,words2[n]);
        }
        break;
        case 3:
        {
            /* choose and copy a word from array of strings randomly */
            srand(time(NULL));
            n = rand() % 7;
            strcpy(word,words3[n]);
        }
        break;
    }

    /* initialize the word with the * character. */
    encrypt( word, unknown);
    fflush(stdin);// clears buffer

    /* loop until the guesses are used up */
    while (wguess < maxtries)
    {
        printf("\n\n%s", unknown);
        printf("\n\nGuess a letter: ");
        scanf("%c", &letter);
        letter = toupper(letter);
        fflush(stdin);// clears buffer

        /* fill secret word with letter if the guess is correct,
        otherwise increment the number of wrong guesses. */
        if (rmatches(letter, word, unknown) == 0)
        {
            printf("\n Oh! That letter isn't in there!\n");
            wguess++;
        }
        else
        {
            printf("\nYou found a letter! That's great!\n");
        }

        /* tell user how many guesses has left. */
        printf("You have %d", maxtries - wguess);
        printf(" guesses left.\n");

        /* check if they guessed the word. */
        if (strcmp( word, unknown) == 0)
        {
            printf("%s\n", word);
            printf("Yeah! You got it!");
            break;
        }
    }
    if (wguess == maxtries)
    {
        printf("\nSorry, you lose...you've been hanged.\n");
        printf("The word was : %s\n", word);
    }
    getch();
    return 0;
}

/* take a one character guess and the secret word, and fill in the
unfinished guessword. Returns number of characters matched.
Also, returns zero if the character is already guessed. */

int rmatches(char guess, char secretword[], char guessword[])
{
    int i;
    int matches = 0;
    for (i = 0; secretword[i] != '\0'; i++)
    {
        /* check if we already matched this letter in a previous guess */
        if (guess == guessword[i])
            return 0;
        /* is the guess in the secret word? */
        if (guess == secretword[i])
        {
            guessword[i] = guess;
            matches++;
        }
    }
    return matches;
}

/* initialize the unknown word */
void encrypt(char word[], char unknown[])
{
    int i;
    int length = strlen(word);
    for (i = 0; i < length; i++)
        unknown[i] = '*';
    unknown[i] = '\0';
}
