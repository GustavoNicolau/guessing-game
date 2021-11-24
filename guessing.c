#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("********************************\n");
    printf("* Welcome to the guessing game *\n");
    printf("********************************\n");

    srand(time(0));

    int randomNumber = rand();

    int guess;
    int attemps = 1;
    double score = 1000;
    long level;

    printf("select a level: \n");
    printf("(1) Easy (2) Medium (3) Hard (4) Hardcore\n");
    scanf("%d", &level);
    switch (level)
    {
    case 1:
        level = 100;
        break;
    case 2:
        level = 1000;
        break;
    case 3:
        level = 10000;
        break;
    default:
        level = 1000000000;
        break;
    }
    int secretNumber = randomNumber % level;
    while (1)
    {

        printf("what's your guess ?\n");
        printf("Attempt %d\n", attemps);

        scanf("%d", &guess);
        int correct = guess == secretNumber;
        int greater = guess > secretNumber;
        printf("your guess was %d\n", guess);
        if (guess < 0)
        {
            printf("number must be greater than 0\n");

            continue;
        }

        if (correct)
        {
            printf("oh, you got it right\n");
            break;
        }

        else if (greater)
        {
            printf("your guess is greater than the secret number\n");
        }
        else
        {
            printf("your guess is less than the secret number\n");
        }

        attemps++;
        double lostScore = (double)(guess - secretNumber) / 2;
        score = score - abs(lostScore);
    }

    printf("game over \n");
    printf("you won in %d attempts\n", attemps);
    printf("Your score: %.2f", score);
    return 0;
}
