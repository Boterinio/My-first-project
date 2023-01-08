#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<math.h>

enum difficulty{easy = 1,medium,hard,insane};

int codeCreate();
int getUserChoice();
int exacltyAnswer(int code,int guess);
int halfAccurateAnswer(int code,int guess);
void heartDraw();

int main()
{
	char flag = ' ';
	do
	{
		int choice = 0,input = 0,counter = 0,turns = 0,perfactAns = 0,halfAccurateAns = 0,code = 0;
		srand(time(NULL));
		code = codeCreate();
		printf("Welcome to ""MAGSHIMIM CODE-BREAKER""!!!\nA secret password was chosen to protect the credit card of Pancratius,\nthe descendant of Antiochus.\nYour mission is to stop Pancratius by revealing his secret password.\n\nThe rules are as follows:\n1. In each round you try to guess the secret password (4 distinct digits)\n2. After every guess you'll receive two hints about the password\n   HITS:   The number of digits in your guess which were exactly right.\n   MISSES: The number of digits in your guess which belongs to\n           the password but were miss-placed.\n3. If you'll fail to guess the password after a certain number of rounds\n   Pancratius will buy all the gifts for Hanukkah!!!\n\n\nPlease choose the game level:\n1 - Easy (20 rounds)\n2 - Moderate (15 rounds)\n3 - Hard (10 rounds)\n4 - Crazy (random number of rounds 5-25)\n");
		do
		{
			printf("Please choose the game level  ");
			choice = getch();
			putch(choice);
			printf("\n");
		}while(choice != '1' && choice != '2' && choice != '3' && choice != '4');
		choice -= 48;//for example the value of '1' in ascii equal 49 so to get 1 we need to subtract 48
		printf("%d\n",code);
		switch(choice)
		{
			case easy:
				turns = 20;
				break;
			case medium:
				turns = 15;
				break;
			case hard:
				turns = 10;
				break;
			case insane:
				turns = rand()%21+5;
				break;
			
		}
		for(int i=0;i<turns;i++)
		{
			if(choice != 4)
				printf("you have %d guesses left\n",turns-counter);
			counter ++;
			input = getUserChoice();	
			perfactAns = exacltyAnswer(code,input);
			halfAccurateAns = halfAccurateAnswer(code,input);
			if (code == input)
			{
				printf("You got 4 HITS\n\nIt took you only %d guesses, you are a professional code breaker!\n\n",counter);
				break;
			}
			else 
			{
				printf("your HITS: %d\nyour misses: %d\n",perfactAns,halfAccurateAns);
			}
		}
		do
		{
			printf("Would you like to play again? (y/n):\n");
			scanf("%c",&flag);
		}while(flag != 'n' && flag != 'y' && flag != 'N' && flag != 'Y');
	}
	while(flag == 'y' || flag == 'Y');
	printf("\n\nThank you for play!\nSee you soon goodbye:)\n");
	heartDraw();
	getchar();
	getchar();
	return 0;
}

/*
function that create the code and check is proper
input: none
output: the function return the random code
*/ 
int codeCreate()
{
	int code = 0;
	int units = 0;
	int tens = 0;
	int hundreds = 0;
	int thousand = 0;
	srand(time(NULL));
	do
	{
    	units = rand() % 6 + 1;
    	tens = rand() % 6 + 1;
    	hundreds = rand() % 6 + 1;
    	thousand = rand() % 6 + 1;
		code = thousand * 1000 + hundreds * 100 + tens * 10 + units;
	}
	while(units == tens || units == hundreds || units == thousand || tens == hundreds || tens == thousand || hundreds == thousand || units > 6 || tens > 6 || hundreds > 6 || thousand > 6);
	return code;
}
/*
function that return the proper input
input: none
output: the function return the proper input
*/ 
int getUserChoice()
{
	int input = 0;
	int units = 0;
	int tens = 0;
	int hundreds = 0;
	int thousand = 0;
	printf("Enter your guess (only 1-6, no ENTER is needed)\n");
	thousand = getch();
	printf("%c",thousand);
	hundreds =  getch();
	printf("%c",hundreds);
	tens = getch();
	printf("%c",tens);
	units = getch();
	printf("%c\n",units);
	units -= 48;
	tens -= 48;
	hundreds -= 48;
	thousand -= 48;
	input = thousand * 1000 + hundreds * 100 + tens * 10 + units;
	while(units == tens || units == hundreds || units == thousand || tens == hundreds || tens == thousand || hundreds == thousand || units > 6 || tens > 6 || hundreds > 6 || thousand > 6 || input<1000 || units < 1 || tens < 1 || hundreds < 1 || thousand < 1)
	{
		printf("Invalid Input!\nEnter your guess (only 1-6, no ENTER is needed)\n");
		thousand = getch();
		printf("%c",thousand);
		hundreds =  getch();
		printf("%c",hundreds);
		tens = getch();
		printf("%c",tens);
		units = getch();
		printf("%c\n",units);
		units -= 48;
		tens -= 48;
		hundreds -= 48;
		thousand -= 48;
		input = thousand * 1000 + hundreds * 100 + tens * 10 + units;
	}
	return input;
}
/*
function that check the guess and return how many exactly answers are
input: the code and the guess 
output: the function return the amount of the exactly answers 
*/
int exacltyAnswer(int code,int guess)
{
	int ans = 0;
	if((code % 10) == (guess % 10))
		ans++;
	if((code / 10 % 10) == (guess / 10 % 10))
		ans++;
	if((code / 100 % 10) == (guess / 100 % 10))
		ans++;
	if((code / 1000) == (guess / 1000))
		ans++;
	return ans;
}
/*
function that check the guess and return how many half accurate answers are
input: the code and the guess 
output: the function return the amount of half accurate answers 
*/
int halfAccurateAnswer(int code,int guess)
{
	int ans = 0;
	if((code % 10) == (guess / 10 % 10) || (code % 10) == (guess / 100 % 10) || (code % 10) == (guess / 1000))
		ans++;
	if((code / 10 % 10) == (guess % 10) || (code / 10 % 10) == (guess / 100 % 10) || (code / 10 % 10) == (guess / 1000))
		ans++;
	if((code / 100 % 10) == (guess / 10 % 10) || (code / 100 % 10) == (guess % 10) || (code / 100 % 10) == (guess / 1000))
		ans++;
	if((code / 1000) == (guess / 10 % 10) || (code / 1000) == (guess / 100 % 10) || (code / 1000) == (guess % 10))
		ans++;
	return ans;
}
//function that prints heart
void heartDraw()
{
    int size = 5;
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y <= 4*size; y++)
        {
            double dist1 = sqrt(pow(x - size, 2) + pow(y - size, 2));
            double dist2 = sqrt(pow(x - size, 2) + pow(y - 3*size, 2));
            if (dist1 < size + 0.5 || dist2 < size + 0.5) 
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    for (int x = 1; x < 2*size; x++)
    {
        for (int y = 0; y < x; y++)
            printf(" ");
        for (int y = 0; y < 4*size + 1 - 2*x; y++)
            printf("*");
        printf("\n");
    }
}