/********************
  Program in which computer plays craps.
  Program is not inter-active. Computer plays the game until it is finished.
*********************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//defining integral constants
enum Status{MOVEFORWARD,WINNER,LOSS} status;

int Roll(void);
void gameStatus();


int main()
{
    //seed generator for random numbers.
    srand(time(NULL));

    gameStatus();

    return 0;
}
//Function to determine what sum player rolled.
int Roll(void)
{
    int firstDie, secondDie, sum;

    firstDie = 1+(rand()%6);
    secondDie = 1+(rand()%6);

    //After dice have come to rest, sum of spots on two upward faces is calculated.
    sum = firstDie + secondDie;

    printf("Player rolled %d + %d = %d",firstDie,secondDie,sum);
    printf("\n");
    return sum;
}
//Function to determine status of the game. Player may win or lose on first throw.
void gameStatus()
{
    printf("Jessica Taylor - Project 4: Craps\n");
    printf("\n");

    int gamePoint, gameResult;
    gameResult = Roll();

    switch(gameResult)
    {
        //If sum of first throw is 7 or 11, player wins.
        case 7:
        case 11:
            status= WINNER;
            break;
        //If sum of first throw is 2, 3, or 12, player loses.
        case 2:
        case 3:
        case 12:
            status= LOSS;
            break;
        //If sum of first throw is 4, 5, 6, 7, 8, 9, or 10, game continues.
        default:
            status = MOVEFORWARD;
            gamePoint = gameResult;
            printf("\n");
            printf("Point is %d, The game continues:\n", gamePoint);
            printf("\n");
    }
    while(status == MOVEFORWARD)
    {
        gameResult = Roll();
        //Player wins by making points.
        if (gameResult == gamePoint)
        {
            status = WINNER;
        //Player loses by rolling 7 before making point.
        }
        else if (gameResult == 7)
        {
            status= LOSS;
        }
    }
    if(status == WINNER)
    {
        printf("\nPlayer wins.\n");
    }
    else
    {
        printf("\nPlayer loses.\n");
    }
    printf("\n");
    printf("Jessica Taylor - End of Project 4\n");
}

