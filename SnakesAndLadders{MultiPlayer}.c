#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int diceGenerator()
{
	srand(time(NULL));
	int randomNumber = 1 + (rand()%6);
	return randomNumber;
}
int diceRoller()
{
	int diceInitializer;
	TryAgain:
	printf("Press 1 to roll dice\n");
	scanf("%d", & diceInitializer);

	if(diceInitializer == 1)
	{
		return diceGenerator();
	}
	else
	{
		printf("Wrong input!\n");
		printf("Try Again\n");
		goto TryAgain;
	}	
}

int position_checker(int pos)
{
 if (pos == 4)
    {
        printf("You climbed a ladder\n");
        pos = 14;
    }
    else if (pos == 9)
    {
        printf("You climbed a ladder\n");
        pos = 31;
    }
    else if (pos == 17)
    {
        printf("A snake bit you\n");
        pos = 7;
    }
    else if (pos == 20)
    {
        printf("You climbed a ladder\n");
        pos = 38;
    }
    else if (pos == 29)
    {
        printf("You climbed a ladder\n");
        pos = 84;
    }
    else if (pos == 40)
    {
        printf("You climbed a ladder\n");
        pos = 59;
    }
    else if (pos == 60)
    {
        printf("A snake bit you\n");
        pos = 18;
    }
    else if (pos == 63)
    {
        printf("You climbed a ladder\n");
        pos = 81;
    }
    else if (pos == 68)
    {
        printf("A snake bit you\n");
        pos = 49;
    }
    else if (pos == 71)
    {
        printf("You climbed a ladder\n");
        pos = 91;
    }
    else if (pos == 87)   
    {
        printf("A snake bit you\n");
        pos = 24;
    }
    else if (pos == 93)
    {
        printf("A snake bit you\n");
        pos = 73;
    }
    else if (pos == 99)
    {
        printf("A snake bit you\n");
        pos = 46;
    }
    else
    {
        pos = pos;
    }
    return pos;
}


int player1(int position)
{
	int dice;	
	printf("Present turn: Player1\n");
	printf("Current position: %d\n", position);
	if(position == 0)
	{
		dice = diceRoller();
		if ((dice==1)||(dice==6))
		{
			printf("You rolled a %d\n", dice);
			printf("Game begins for Player1\n");
			return 1;
		}
		else 
		{
			printf("You rolled a %d\n", dice);
			printf("Game begins on rolling 1 or 6\n");
			return 0;
		}
		
	}
	else if (position != 0)
	{
		dice = diceRoller();
		printf("You rolled a %d\n", dice);
		if (dice == 6)
		{
			position = position + 6;
			if(position > 100)
			{
				position = position - 6;
			}
			printf("You got a second roll\n");
			dice = diceRoller();
			printf("You rolled a %d\n", dice);
			position = position + dice;
			if(position > 100)
                        {
                                position = position - dice;
                        }
			printf("Your current position: %d\n", position);
			position = position_checker(position);				
		}
		else if (dice != 6)
		{
			position = position + dice;
			if(position > 100)
                        {
                                position = position - 6;
                        }
			printf("Your current position: %d\n", position);
			position = position_checker(position);
		}	
		return position;
	}
}

int player2(int position)
{
        int dice;
        printf("Present turn: Player2\n");
        printf("Current position: %d\n", position);
        if(position == 0)
        {
                dice = diceRoller();
                if ((dice==1)||(dice==6))
                {
                        printf("You rolled a %d\n", dice);
                        printf("Game begins for Player2\n");
                        return 1;
                }
                else
                {
                        printf("You rolled a %d\n", dice);
                        printf("Game begins on rolling 1 or 6\n");
                        return 0;
                }
        
        }
        else if (position != 0)
        {
                dice = diceRoller();
                printf("You rolled a %d\n", dice);
                if (dice == 6)
                {
                        position = position + 6;
                        if(position > 100)
                        {
                                position = position - 6;
                        }
                        printf("You got a second roll\n");
                        dice = diceRoller();
                        printf("You rolled a %d\n", dice);
                        position = position + dice;
                        if(position > 100)
                        {
                                position = position - dice;
                        }
                        printf("Your current position: %d\n", position);
                        position = position_checker(position);
                }
                else if (dice != 6)
                {
                        position = position + dice;
                        if(position > 100)
                        {
                                position = position - 6;
                        }
                        printf("Your current position: %d\n", position);
                        position = position_checker(position);
                }       
                return position;
	}
}

int main()
{
	printf("Welcome to Snakes and Ladders\n");
	int pos1 = 0, pos2 = 0;
	
	while((pos1 != 100)&&(pos2 != 100))
	{
		if(pos2 != 100){
		pos1 = player1(pos1);
		}
		if(pos1 != 100){
		pos2 = player2(pos2);
		}
	}
	
	if(pos1 == 100)
	{
		printf("Player1 won the game\n");
	}
	else
	{
		printf("Player2 won the game\n");
	}
	return 0;
}

				

