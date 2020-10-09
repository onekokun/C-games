#include <iostream>
#include<windows.h>
#include<ctime>
#include<conio.h>

using namespace std;

int first;
int grid[][3] = {{1,2,3},{4,5,6},{7,8,9}};

void showGrid()
{
    cout<<"\n\n\n";

    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
            if(grid[i][j]==79)
                cout<<"\t"<<"X";
            else if(grid[i][j]==88)
                cout<<"\t"<<"O";
            else
            cout<<"\t"<<grid[i][j];

        cout<<"\n\n\n";
    }
}

int getMove()
{
    char mov = getch();
    if(mov=='1' || mov=='2' || mov=='3'|| mov=='4' || mov=='5' || mov=='6' || mov=='7' || mov=='8' || mov=='9')
        return mov-'0';
    else
        {
            cout<<"Not a valid Move, Play your Move once More\nyour move should be a number between 1 to 9\n"<<endl;
            system("pause");
            getMove();
        }
}

void warning()
{
    cout<<"sorry, this place is already occupied, please play some other move"<<endl;
    system("pause");
    first = 1-first;
}
void exeMove(int x,char sym)
{

        if(x==1)
        {   if(grid[0][0]>10)
                warning();

            else
                grid[0][0] = sym;
        }

        else if(x==2)
        {   if(grid[0][1]>10)
                warning();

            else
                grid[0][1] = sym;
        }

         else if(x==3)
        {   if(grid[0][2]>10)
                warning();

            else
                grid[0][2] = sym;
        }

        else if(x==4)
        {   if(grid[1][0]>10)
                warning();

            else
                grid[1][0] = sym;
        }

        else if(x==5)
        {   if(grid[1][1]>10)
                warning();

            else
                grid[1][1] = sym;
        }

         else if(x==6)
        {   if(grid[1][2]>10)
                warning();

            else
                grid[1][2] = sym;
        }

         else if(x==7)
        {   if(grid[2][0]>10)
                warning();

            else
                grid[2][0] = sym;
        }

         else if(x==8)
        {   if(grid[2][1]>10)
                warning();

            else
                grid[2][1] = sym;
        }

        else if(x==9)
        {   if(grid[2][2]>10)
                warning();

            else
                grid[2][2] = sym;
        }
}

bool someoneWon()
{
    bool won = false;


if(    (grid[0][0] == grid[0][1] && grid[0][1]==grid[0][2]) ||
       (grid[1][0] == grid[1][1] && grid[1][1]==grid[1][2]) ||
       (grid[2][0] == grid[2][1] && grid[2][1]==grid[2][2]) ||
       (grid[0][0] == grid[1][0] && grid[1][0]==grid[2][0]) ||
       (grid[0][1] == grid[1][1] && grid[1][1]==grid[2][1]) ||
       (grid[0][2] == grid[1][2] && grid[1][2]==grid[2][2]) ||
       (grid[0][0] == grid[1][1] && grid[1][1]==grid[2][2]) ||
       (grid[0][2] == grid[1][1] && grid[1][1]==grid[2][0])  )

       won = true;

    return won;

}
void makemove(string name)
{
        cout<<name<<" , enter your move ... "<<endl;
}

int main()
{
    srand(time(0));
    bool run = true;
    string p1,p2;
     int muv;


    cout<<"\t\n\nPlayer 1, Enter your name : ";
    cin>>p1;
    cout<<"\t\n\nPlayer 2, Enter your name : ";
    cin>>p2;

    system("cls");
    int symNum = rand()%2;
    char sym[] = {'O','X'};
    string name[] = {p1,p2};

    char sP1 = sym[symNum];
    char sP2 = sym[1-symNum];

    cout<<"\n\n\t"<<p1<<" has been assigned "<<sP1<<"\n\n"<<endl;
    cout<<"\t"<<p2<<" has been assigned "<<sP2<<"\n\n"<<endl;

    first = rand()%2;
    cout<<name[first]<<" will make the first move"<<endl;
    system("pause");

    while(run)
    {
        showGrid();
        makemove(name[first]);

            muv = getMove();

        exeMove(muv,sym[first]);

        first = 1-first;

        if(someoneWon())
        {
            run = false;
        }
       system("cls");
    }

    cout<<"\n\n\n\t\t\t"<<name[1-first]<<" WON THE MATCH !!!!!!"<<endl;
    char choice;

    return 0;
}
