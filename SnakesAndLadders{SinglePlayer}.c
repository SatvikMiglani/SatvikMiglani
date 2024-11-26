#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dice_roller()
{
	srand(time(NULL));
	int n = 1 + (rand()%6) ;
	return n;
}

void initializer_check(int number)
{
	if(number != 0)
	{
		printf("Wrong input!\n");
		printf("Press 0 to roll the dice:\n");
		scanf("%d", &number);
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

int main()
{
	int position = 0,initializer,dice;
	printf("\t\tWelcome to SnakesAndLadders\n");
	while(position != 100)
	{
		if (position == 0)
		{
			printf("Current position: 0\n");
			printf("Game begins on rolling a 1 or 6\n");
			printf("Press 0 to roll the dice:\n");
			scanf("%d", &initializer);

			initializer_check(initializer);
			
			dice = dice_roller();
			
			if ((dice == 1) || (dice == 6))
			{
				printf("You rolled a %d", dice);
				printf("Game begins now\n");
				position = 1;			
			}
			else
			{
				while ((dice != 1)&&(dice != 6))
				{
					printf("Press 0 to roll the dice:\n");
                        		scanf("%d", &initializer);
                        
                       			initializer_check(initializer);
                        
                        		dice = dice_roller(); 					
					printf("You rolled a %d\n", dice);
				}
				printf("Game begins now\n");
				position = 1;
			}
		}
		else
		{
			printf("Current position: %d\n", position);
			printf("Press 0 to roll the dice:\n");
                        scanf("%d", &initializer);
                        
                        initializer_check(initializer);
 
                        dice = dice_roller();

			printf("You rolled a %d\n", dice);
			position = position + dice;
			
			position = position_checker(position);

			if(position > 100)
			{
				position = position - dice;
			}
		}
	}	
			 
	printf("You reached 100\n");
	printf("Game Over");
	return 0;
}
