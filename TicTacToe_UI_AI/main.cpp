#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

void intializer();
void printer();
void checker();
void cursor();
void board_updater(int,int);
void AI();
char board[3][3];
int i=0,k=0,a,b;

int main()
{
    int j;
    intializer();

    for(i=0;i<5;i++)
    {

        printer();
        cout<<"Player 1: "; cursor();
        board_updater(a,b);
        printer(); cout<<endl;
        checker();
        if(i<5)
        {
        k=0;
        AI();
        printer(); cout<<endl;
       checker();
        }

    }

    cout<<endl<<" ending press 'g' to quit ";
    cin>>j;
    cout<<endl<<"quitting";

    return 0;
}


void board_updater (int a,int b)

{
    board[a][b]='O';

}

void printer()
{

    for(int c=0;c<55;c++)
    {
        cout<<endl;
    }

    cout<<"Use W,A,S,D to navigate. Press SpaceBar to place O "<<endl;
    cout<<"TIC TAC TOE "<<endl;
    cout<<"3 "<<board[0][2]<<" "<<board[1][2]<<" "<<board[2][2]<<endl;
    cout<<"2 "<<board[0][1]<<" "<<board[1][1]<<" "<<board[2][1]<<endl;
    cout<<"1 "<<board[0][0]<<" "<<board[1][0]<<" "<<board[2][0]<<endl;
    cout<<"  "<<"1 "<<"2 "<<"3 "<<endl;

}

void intializer()
{
    for(int x=0;x<3;x++)
    {
        for(int y=0;y<3;y++)
        {
            board[x][y]='*';
        }
    }
}

void checker()
{
    //Column
    for(int c=0;c<3;c++)
    {
        if((board[c][0]==board[c][1])&&(board[c][0]==board[c][2]))
        {
            if(board[c][0]=='O') {cout<<" Winner is player 1 "; i=5;}
            else if(board[c][0]=='X') {cout<<" winner is AI";i=5;}
        }
    }
  //Row
    for(int r=0;r<3;r++)
    {
        if((board[0][r]==board[1][r])&&(board[0][r]==board[2][r]))
        {
            if(board[0][r]=='O') {cout<<" Winner is player 1 "; i=5;}
            else if(board[0][r]=='X') {cout<<" winner is AI";i=5;}
        }
    }

    //Diagonal
     if((board[0][2]==board[1][1])&&(board[2][0]==board[1][1]))
        {
            if(board[0][2]=='O') {cout<<" Winner is player 1 "; i=5;}
            else if(board[0][2]=='X') {cout<<" winner is AI";i=5;}
        }

      if((board[0][0]==board[1][1])&&(board[0][0]==board[2][2]))
        {
            if(board[0][0]=='O') {cout<<" Winner is player 1 "; i=5;}
            else if(board[0][0]=='X') {cout<<" winner is AI";i=5;}
        }

}


void AI()
{
    int a,b,c,sum;

    //Column
    if(k==0)
    {
    for(int l=0;l<3;l++)
    {
        a=board[l][0]; b=board[l][1]; c=board[l][2];
        sum=a+b+c;
        if(sum==200)
        {
            k=1;
           if(a==42) board[l][0]='X';
            else if (b==42) board[l][1]='X';
            else if (c==42) board[l][2]='X';
        }
    }

    }

    if(k==0)
        {
  //Row
    for(int r=0;r<3;r++)
    {

        a=board[0][r]; b=board[1][r]; c=board[2][r];
        sum=a+b+c;

        if(sum==200)
        {
            k=1;
           if(a==42) board[0][r]='X';
            else if (b==42) board[1][r]='X';
            else if (c==42) board[2][r]='X';
        }

    }
        }

        if(k==0)
        {
    //Diagonal
     a=board[0][2]; b=board[1][1]; c=board[2][0];
        sum=a+b+c;
        if(sum==200)
        {
             if(a==42) board[0][2]='X';
            else if (b==42) board[1][1]='X';
            else if (c==42) board[2][0]='X';
        }
        }

        if(k==0)
            {
       a=board[0][0]; b=board[1][1]; c=board[2][2];
        sum=a+b+c;
        if(sum==200)
        {
            k=1;
             if(a==42) board[0][0]='X';
            else if (b==42) board[1][1]='X';
            else if (c==42) board[2][2]='X';
        }
            }

    if(k==0)
    {

        if(board[1][1]=='*') board[1][1]='X';
        else if(board[0][0]=='*') board[0][0]='X';

        else
        {
            for(int e=0;e<3;e++)
            {

                for (int q=0;q<3;q++)

                {
                   if(board[e][q]=='*') { board[e][q]='X'; q=3; e=3; }
                }

            }
        }

    }

}

void cursor()
{
    int m=1,n=1;
    char inp='9',prev=board[1][1];
    board[1][1]='-';

    while(inp!=' ')
    {
        printer();
        cout<<"Player 1 ";
        inp=getch();

        switch(inp)
        {

            case 'w':  board[m][n]=prev; prev=board[m][n+1]; board[m][n+1]='-'; n+=1; break;
            case 'a':  board[m][n]=prev; prev=board[m-1][n]; board[m-1][n]='-'; m-=1; break;
            case 's':  board[m][n]=prev; prev=board[m][n-1]; board[m][n-1]='-'; n-=1; break;
            case 'd':  board[m][n]=prev; prev=board[m+1][n]; board[m+1][n]='-'; m+=1; break;

        }

        printer();
    }

    a=m;b=n;

}

