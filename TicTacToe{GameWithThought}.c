 #include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

void PrintPresentState(char array[3][3]);
void Generation(char array[3][3],int turn);
void Placement(char array[3][3]);
void CheckPlacement(char array[3][3],int x,int y);
int ConditionCheck(char array[3][3], int *winner);

void Generation(char array[3][3],int turn)
{
	srand(time(0));
	int randomRow, randomColumn,randomBlock;
	if(turn == 1)
	{
		randomBlock = 1 + (rand()%4);
		if (randomBlock == 1)
		{
			array[0][0] = 'O';
		}
		else if(randomBlock == 2)	
		{
			array[0][2] = 'O';
		}
		else if(randomBlock == 3)
		{
			array[2][0] = 'O';
		}
		else if(randomBlock == 4)
		{
			array[2][2] = 'O';
		}
		PrintPresentState(array);
		return;
	}
	else if(turn != 1)
	{
		if((array[0][0]=='X')&&(array[0][1]=='X')&&(array[0][2]!='X')&&(array[0][2]!='O'))
		{
				array[0][2]='O';
		}
		else if((array[0][0]=='X')&&(array[0][2]=='X')&&(array[0][1]!='X')&&(array[0][1]!='O'))
		{
				array[0][1]='O';
		}
		else if((array[0][0]=='X')&&(array[1][0]=='X')&&(array[2][0]!='X')&&(array[2][0]!='O'))
		{
				array[2][0]='O';
		}
		else if((array[0][0]=='X')&&(array[2][0]=='X')&&(array[1][0]!='X')&&(array[1][0]!='O'))
		{
				array[1][0]='O';
		}
		else if((array[0][0]=='X')&&(array[1][1]=='X')&&(array[2][2]!='X')&&(array[2][2]!='O'))
		{
				array[2][2]='O';
		}
		else if((array[0][0]=='X')&&(array[2][2]=='X')&&(array[1][1]!='X')&&(array[1][1]!='O'))
		{
				array[1][1]='O';
		}
		else if((array[0][1]=='X')&&(array[0][2]=='X')&&(array[0][0]!='X')&&(array[0][0]!='O'))
		{
				array[0][0]='O';
		}
		else if((array[0][1]=='X')&&(array[0][0]=='X')&&(array[0][2]!='X')&&(array[0][2]!='O'))
		{
				array[0][2]='O';
		}
		else if((array[0][1]=='X')&&(array[1][1]=='X')&&(array[2][1]!='X')&&(array[2][1]!='O'))
		{
				array[2][1]='O';
		}
		else if((array[0][1]=='X')&&(array[2][1]=='X')&&(array[1][1]!='X')&&(array[1][1]!='O'))
		{
				array[1][1]='O';
		}
		else if((array[0][2]=='X')&&(array[1][2]=='X')&&(array[2][2]!='X')&&(array[2][2]!='O'))
		{
				array[2][2]='O';
		}
		else if((array[0][2]=='X')&&(array[2][2]=='X')&&(array[1][2]!='X')&&(array[1][2]!='O'))
		{
				array[1][2]='O';
		}
		else if((array[0][2]=='X')&&(array[1][1]=='X')&&(array[2][0]!='X')&&(array[2][0]!='O'))
		{
				array[2][0]='O';
		}
		else if((array[0][2]=='X')&&(array[2][0]=='X')&&(array[1][1]!='X')&&(array[1][1]!='O'))
		{
				array[1][1]='O';
		}
		else if((array[1][0]=='X')&&(array[1][1]=='X')&&(array[1][2]!='X')&&(array[1][2]!='O'))
		{
				array[1][2]='O';
		}
		else if((array[1][0]=='X')&&(array[1][2]=='X')&&(array[1][1]!='X')&&(array[1][1]!='O'))
		{
				array[1][1]='O';
		}
		else if((array[2][0]=='X')&&(array[2][1]=='X')&&(array[2][2]!='X')&&(array[2][2]!='O'))
		{
				array[2][2]='O';
		}
		else if((array[2][0]=='X')&&(array[2][2]=='X')&&(array[2][1]!='X')&&(array[2][1]!='O'))
		{
				array[2][1]='O';
		}
		else if((array[0][0]=='O')&&(array[0][1]=='O')&&(array[0][2]!='X')&&(array[0][2]!='O'))
		{
				array[0][2]='O';
		}
		else if((array[0][0]=='O')&&(array[0][2]=='O')&&(array[0][1]!='X')&&(array[0][1]!='O'))
		{
				array[0][1]='O';
		}
		else if((array[0][0]=='O')&&(array[1][0]=='O')&&(array[2][0]!='X')&&(array[2][0]!='O'))
		{
				array[2][0]='O';
		}
		else if((array[0][0]=='O')&&(array[2][0]=='O')&&(array[1][0]!='X')&&(array[1][0]!='O'))
		{
				array[1][0]='O';
		}
		else if((array[0][0]=='O')&&(array[1][1]=='O')&&(array[2][2]!='X')&&(array[2][2]!='O'))
		{
				array[2][2]='O';
		}
		else if((array[0][0]=='O')&&(array[2][2]=='O')&&(array[1][1]!='X')&&(array[1][1]!='O'))
		{
				array[1][1]='O';
		}
		else if((array[0][1]=='O')&&(array[0][2]=='O')&&(array[0][0]!='X')&&(array[0][0]!='O'))
		{
				array[0][0]='O';
		}
		else if((array[0][1]=='O')&&(array[0][0]=='O')&&(array[0][2]!='X')&&(array[0][2]!='O'))
		{
				array[0][2]='O';
		}
		else if((array[0][1]=='O')&&(array[1][1]=='O')&&(array[2][1]!='X')&&(array[2][1]!='O'))
		{
				array[2][1]='O';
		}
		else if((array[0][1]=='O')&&(array[2][1]=='O')&&(array[1][1]!='X')&&(array[1][1]!='O'))
		{
				array[1][1]='O';
		}
		else if((array[0][2]=='O')&&(array[1][2]=='O')&&(array[2][2]!='X')&&(array[2][2]!='O'))
		{
				array[2][2]='O';
		}
		else if((array[0][2]=='O')&&(array[2][2]=='O')&&(array[1][2]!='X')&&(array[1][2]!='O'))
		{
				array[1][2]='O';
		}
		else if((array[0][2]=='O')&&(array[1][1]=='O')&&(array[2][0]!='X')&&(array[2][0]!='O'))
		{
				array[2][0]='O';
		}
		else if((array[0][2]=='O')&&(array[2][0]=='O')&&(array[1][1]!='X')&&(array[1][1]!='O'))
		{
				array[1][1]='O';
		}
		else if((array[1][0]=='O')&&(array[1][1]=='O')&&(array[1][2]!='X')&&(array[1][2]!='O'))
		{
				array[1][2]='O';
		}
		else if((array[1][0]=='O')&&(array[1][2]=='O')&&(array[1][1]!='X')&&(array[1][1]!='O'))
		{
				array[1][1]='O';
		}
		else if((array[2][0]=='O')&&(array[2][1]=='O')&&(array[2][2]!='X')&&(array[2][2]!='O'))
		{
				array[2][2]='O';
		}
		else if((array[2][0]=='O')&&(array[2][2]=='O')&&(array[2][1]!='X')&&(array[2][1]!='O'))
		{
				array[2][1]='O';
		}
		else
		{
			regenerate:
			randomRow = rand() % 3;
			randomColumn = rand() % 3;
	
			if((array[randomRow][randomColumn]=='X')||(array[randomRow][randomColumn]=='O'))
			{
				goto regenerate;
			}
			else
			{
				array[randomRow][randomColumn] = 'O';
			}
		}
		PrintPresentState(array);
		return;
	}
}

void Placement(char array[3][3])
{
	int x,y;
	printf("Enter the row in which you want to place \'X\': ");
	scanf("%d", &x);
	printf("Enter the column in which you want to place \'X\': ");
	scanf("%d", &y);
	
	CheckPlacement(array,x,y);
}

void PrintPresentState(char array[3][3])
{
	printf("%c|%c|%c\n",array[0][0],array[0][1],array[0][2]);
	printf("-----\n");
	printf("%c|%c|%c\n",array[1][0],array[1][1],array[1][2]);
	printf("-----\n");
	printf("%c|%c|%c\n",array[2][0],array[2][1],array[2][2]);
}

void CheckPlacement(char array[3][3],int x,int y)
{
	if(array[x-1][y-1]=='X')
	{
		printf("X is already placed at the entered position.\n");
		printf("Try Again:\n");
		printf("Enter the values of row and column, respectively: ");
		scanf("%d %d", &x, &y);
		CheckPlacement(array,x,y);
	}
	else if(array[x-1][y-1]=='O')                   
        {
                printf("O is already placed at the entered position.\n");
                printf("Try Again:\n");
                printf("Enter the values of row and column, respectively: ");
                scanf("%d %d", &x, &y);
                CheckPlacement(array,x,y);
        }
	else
	{
		array[x-1][y-1] = 'X';
		PrintPresentState(array);
	}
	
}

int ConditionCheck(char array[3][3], int *winner)
{
	
	if(((array[0][0]=='X')&&(array[0][1]=='X')&&(array[0][2]=='X'))||((array[1][0]=='X')&&(array[1][1]=='X')&&(array[1][2]=='X'))||((array[2][0]=='X')&&(array[2][1]=='X')&&(array[2][2]=='X'))||((array[0][0]=='X')&&(array[1][1]=='X')&&(array[2][2]=='X'))||((array[0][2]=='X')&&(array[1][1]=='X')&&(array[2][0]=='X'))||((array[0][0]=='X')&&(array[1][0]=='X')&&(array[2][0]=='X'))||((array[0][1]=='X')&&(array[1][1]=='X')&&(array[2][1]=='X'))||((array[0][2]=='X')&&(array[1][2]=='X')&&(array[2][2]=='X')))
	{
		*winner = 0;
		return 1;
	}
	else if(((array[0][0]=='O')&&(array[0][1]=='O')&&(array[0][2]=='O'))||((array[1][0]=='O')&&(array[1][1]=='O')&&(array[1][2]=='O'))||((array[2][0]=='O')&&(array[2][1]=='O')&&(array[2][2]=='O'))||((array[0][0]=='O')&&(array[1][1]=='O')&&(array[2][2]=='O'))||((array[0][2]=='O')&&(array[1][1]=='O')&&(array[2][0]=='O'))||((array[0][0]=='O')&&(array[1][0]=='O')&&(array[2][0]=='O'))||((array[0][1]=='O')&&(array[1][1]=='O')&&(array[2][1]=='O'))||((array[0][2]=='O')&&(array[1][2]=='O')&&(array[2][2]=='O')))
	{
		*winner = 1;
		return 1;
	} 
	
	else 
		return 0;
}
		
int main()
{
	char PresentState[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
	int condition=0,turn = 1;
	int winner=10;
	printf("Welcome to tictactoe\n");
	printf("Rules: \n");
	printf("1) Computer will play as \'O\'\n");
	printf("2) You will play as \'X\'\n");
	printf("3) At each turn you are supposed to enter the row and column of where you want to place X.\n");
	printf("Good Luck and lets begin.\n");

	while(condition != 1)
	{
			printf("Present turn computer:\n");
			sleep(2);
			Generation( PresentState,turn);
			turn++;
			condition = ConditionCheck(PresentState,&winner);
			if((turn == 10)||(condition == 1))
			break;
			
			printf("Present turn Player\n");
			Placement(PresentState);
			condition = ConditionCheck(PresentState,&winner);
			if (condition == 1)
			break;
			else
			turn++;
	}

	if(winner == 0)
	{
			printf("Player wins");
	}
	else if(winner == 1)
	{
			printf("Computer wins");
	}
	else if(winner == 10)
	{
			printf("Tie Game");
	}
	return 0;
}


	
	
