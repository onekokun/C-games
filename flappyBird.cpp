#include<iostream>
#include<conio.h>
#include<ctime>
#define SCREEN_HEIGHT 40
#define SCREEN_WIDTH 50

using namespace std;


bool run = true;
int wallPos1 = SCREEN_WIDTH,wallPos2 = 3*SCREEN_WIDTH/2;
int birdPosX = SCREEN_WIDTH/4,birdPosY = SCREEN_HEIGHT/2;
int wallGap = 5, gapTop1 = (rand()%SCREEN_HEIGHT/2)+10, gapBottom1 = gapTop1+wallGap;
int gapTop2 = (rand()%SCREEN_HEIGHT/2)+10, gapBottom2 = gapTop2+wallGap;
int score = 0;
void printScreen()
{

	for(int i=0;i<SCREEN_HEIGHT;++i)
	{
		cout<<"#";

		for(int j=0;j<SCREEN_WIDTH-2;++j)
		{
			if(i==0 || i==SCREEN_HEIGHT-1)
			{
				cout<<"#";
			}

			else if((j==wallPos1 && (i<=gapTop1 || i>=gapBottom1)) || (j==wallPos2 && (i<=gapTop2 || i>=gapBottom2)))
			{
				if(i==birdPosY && j==birdPosX)
				{
					run = false;
				}

				cout<<"O";
			}

			else if(i==birdPosY && j==birdPosX)
			{
				cout<<">";

				if(j==wallPos1)
                {

                   if  (gapTop1<i && i<gapBottom1)
                    {
                        score++;
                    }
                }

                else if(j==wallPos2)
                {

                   if  (gapTop2<i && i<gapBottom2)
                    {
                        score++;
                    }
                }

			}

			else
			{
				cout<<" ";
			}
		}

		if(wallPos1==0)
        {
            wallPos1 = SCREEN_WIDTH;
            gapTop1 = (rand()%SCREEN_HEIGHT/2)+10;
            gapBottom1 = gapTop1+wallGap;
        }

		if(wallPos2==0)
        {
            wallPos2 = SCREEN_WIDTH;
            gapTop2 = (rand()%SCREEN_HEIGHT/2)+10;
            gapBottom2 = gapTop2+wallGap;
        }

		cout<<"#\n";
	}
}

void moveWall()
{
	wallPos2--;
	wallPos1--;
}

void moveUp(char c)
{
    switch(c)
    {
        case 'w' : birdPosY--; break;
        case 'W' : birdPosY--; break;

        default : birdPosY--;
    }
}

void moveDown()
{

    birdPosY+=1;
}

bool birdInsideScreen()
{
    if(birdPosY<=0 || birdPosY>=SCREEN_HEIGHT-1)
        return false;
    return true;
}

int main(void)
{
    srand(time(0));
    cout<<"\n\n\n\t\t\tWelcome to Sameer's FlappyBird\n\t\t\tPress 'w' key to move the bird upwards "<<endl<<endl;


    system("pause");

	while(run)
	{

        cout<<"\n SCORE : "<<score<<"\n"<<endl;
		printScreen();

		if(!birdInsideScreen())
        {
            run = false;
        }

		moveWall();

		if(kbhit())
        {
            moveUp(getch());

        }
        else
        {
            moveDown();
        }
		system("cls");

	}

    char ch;

	cout<<"\n\n\n\t\t\tYOUR TOTAL SCORE IS : "<<score<<endl;
    system("pause");
    cout<<"enter 'q' to quit : ";
    cin>>ch;
    exit(0);
	return 0;
}

