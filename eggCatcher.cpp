#include<iostream>
#include<conio.h>
#include<ctime>
#define SCREEN_HEIGHT 40
#define SCREEN_WIDTH 60

using namespace std;

//INITIAL DECLARATIONS
int basketLeftEnd = SCREEN_WIDTH/2, basketRightEnd = SCREEN_WIDTH/2+10;
bool run = true;
int eggX1 = rand()%(SCREEN_WIDTH-2)+1,eggY1=0;
int eggX2 = rand()%(SCREEN_WIDTH-2)+1,eggY2=-10;
int eggX3 = rand()%(SCREEN_WIDTH-2)+1,eggY3=-20;
int eggX4 = rand()%(SCREEN_WIDTH-2)+1,eggY4=-30;

int ptr = 0;
int depth = 1;
int score = 0;
int lives = 3;

//FUNCTION DECLARATIONS
bool isEggPos(int,int);
void update(int);

//UTILITY FUNCTIONS
void printScreen()
{

    cout<<"\n USE 'a' TO MOVE THE BUCKET TOWARDS LEFT"<<endl;
    cout<<"\n USE 'd' TO MOVE THE BUCKET TOWARDS RIGHT\n"<<endl;
    cout<<" LIVES REMAINING : "<<lives<<endl;
    cout<<"\n SCORE : "<<score<<endl<<endl;

    for(int i=0;i<SCREEN_HEIGHT;++i)
    {
            cout<<"#";

        for(int j=0;j<SCREEN_WIDTH-2;++j)
        {
            if(i==0 || i==SCREEN_HEIGHT-1)
                cout<<"#";

            else if(i==SCREEN_HEIGHT-2 && (j==basketLeftEnd || j==basketRightEnd))
            {
                cout<<"|";
            }

            else if(isEggPos(i,j))
            {
                cout<<"O";

                if(i==SCREEN_HEIGHT-2)
                {
                    if(basketLeftEnd<=j && j<=basketRightEnd)
                        score++;
                    else if(j<=basketLeftEnd && j<=basketRightEnd)
                        lives--;
                    else if(basketLeftEnd<=j && basketRightEnd<=j)
                        lives--;

                    update(ptr);
                    ptr = (ptr+1)%4;
                }
            }

            else
                cout<<" ";
        }

        cout<<"#\n";
    }


}


void changeBasketPosition(char ch)
{
    switch(ch)
    {
        case 'a' :
            {
                basketLeftEnd-=3;
                basketRightEnd-=3;
            }
        break;
        case 'A' :
            {
                basketLeftEnd-=3;
                basketRightEnd-=3;
            }
        break;
        case 'D' :
            {
                basketLeftEnd+=3;
                 basketRightEnd+=3;
            }
        break;
        case 'd' :
        {
            basketLeftEnd+=3;
             basketRightEnd+=3;
        }

         break;
    }
}

bool isEggPos(int i,int j)
{
    if(i==eggY1 && j==eggX1)
        return true;

    if(i==eggY2 && j==eggX2)
        return true;

    if(i==eggY3 && j==eggX3)
        return true;

    if(i==eggY4 && j==eggX4)
        return true;

    return false;
}

void increaseDepth()
{
        eggY1+=depth;
        eggY2+=depth;
        eggY3+=depth;
        eggY4+=depth;
}

//DRIVER FUNCTION
int main(void)
{
    srand(time(0));

    cout<<"\t\t\t\n\n\n WELCOME TO EGG-CATCHER BY SAMEER YADAV"<<endl;
    system("pause");
    system("cls");

    cout<<"\t\t\t\n\n\n YOU HAVE TO COLECT AS MANY EGGS IN THE BASKET AS YOU CAN !!! GOOD LUCK !!"<<endl;
    system("pause");
    system("cls");

    printScreen();

    while(run)
    {

        printScreen();

        increaseDepth();

        if(lives==0)
            break;

        if(kbhit())
        {
            changeBasketPosition(getch());
        }

        system("cls");
    }


    system("pause");

    system("cls");

    cout<<"THE END\n";
    cout<<"YOUR TOTAL SCORE IS : \n\n"<<score;

    system("pause");


    return 0;
}

void update(int eggVal)
{
    switch(eggVal)
    {
        case 0 :
        {
            eggX1 = rand()%(SCREEN_WIDTH-2)+1;
            eggY1=0;
        }
        break;

        case 1 :
        {
            eggX2 = rand()%(SCREEN_WIDTH-2)+1;
            eggY2=0;
        }
        break;

        case 2 :
        {
            eggX3 = rand()%(SCREEN_WIDTH-2)+1;
            eggY3=0;
        }
        break;

        case 3 :
        {
            rand()%(SCREEN_WIDTH-2)+1;
            eggY4=0;
        }
        break;
    }
}

