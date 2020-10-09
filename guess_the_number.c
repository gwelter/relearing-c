#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int guess_number() {
    int number;
    printf("Please guess a number between 0 and 20: ");
    scanf("%d", &number);
    return number;
}

int main() {
    srand(time(NULL));

    int tries = 5;
    int number = rand() % 20;
    bool guessed = false;
    int guessed_number;

    do
    {
        printf("You have %d tries\n", tries);
        guessed_number = guess_number();
        guessed = guessed_number == number;
        if (guessed) {
            printf("Congratulations, you guessed it!\n");
        } else {
            printf("Sorry, %d is %s than that, guess again\n", guessed_number, number > guessed_number ? "lower" : "greater");
            --tries;
        }
    } while (tries > 0 && !guessed);
    return 0;
}