#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void print();
void board_intializer();
void contagion_(int,int);
void contagion();
int win_lose(int,int);

class block
{
public:

    bool state;
    int to_show;
    bool presence_of_mine;

    block();
    void show();
    void change_state();
    void inc_to_show();

};

block board[7][7];

int main()
{
    srand(time(NULL));
    int x,y,win=0;

    board_intializer();
    print();

    do
    {
    cout<<" Enter Coordinates "; cin>>x>>y;
    board[x][y].change_state(); cout<<endl;

    if(board[x][y].to_show==0)
     {

    for(int i=0;i<6;i++)
    { contagion(); }

     }

    win=win_lose(x,y);
    print();

    } while(win==0);

    if(win==1)
        cout<<endl<<" You Lose "<<endl;
    else if(win==2)
        cout<<endl<<" You Won. Congrats "<<endl;

    cout<<endl<<" Ending Game.... ";

    return 0;
}

void print()
{
    cout<<" MineSweeper Game "<<endl<<endl;
     for(int n=5; n>0; n--)
    {
        cout<<n<<" ";
        for(int m=1; m<6; m++)
        {
            board[m][n].show();
            cout<<" ";
        }
        cout<<endl;
    }
    cout<<"  1 2 3 4 5"<<endl<<endl;
}

void board_intializer()
{

    for(int g=0;g<2;g++)
    {
      int m,n;
      m=rand(); n=rand(); m=m%5+1; n=n%5+1;


      if(board[m][n].presence_of_mine==0)
      {

       board[m][n].presence_of_mine=1;
       board[m][n].to_show=8;

     board[m-1][n-1].inc_to_show();
     board[m-1][n].inc_to_show();
     board[m-1][n+1].inc_to_show();
     board[m][n+1].inc_to_show();
     board[m][n-1].inc_to_show();
     board[m+1][n-1].inc_to_show();
     board[m+1][n].inc_to_show();
     board[m+1][n+1].inc_to_show();

      }

      else if(board[m][n].presence_of_mine==1)
        g-=g;


    }

}

void contagion_(int m,int n)
{
    board[m-1][n-1].change_state();
    board[m-1][n].change_state();
    board[m-1][n+1].change_state();
    board[m][n+1].change_state();
    board[m][n-1].change_state();
    board[m+1][n-1].change_state();
    board[m+1][n].change_state();
    board[m+1][n+1].change_state();

}



void contagion()
{
    int m,n;

    for(m=1;m<6;m++)
    {
        for (n=1;n<6;n++)
        {
            if(board[m][n].state==1&&board[m][n].to_show==0)
            {
                contagion_(m,n);
            }

            }

        }
    }

int win_lose(int x,int y)
{
    int c=0,m,n;

    for(m=1;m<6;m++)
    {
        for (n=1;n<6;n++)
        {
            if(board[m][n].state==1)
            {
                c+=1;
            }

        }

    }

    if(board[x][y].presence_of_mine==1)
    {
        return 1;
    }

    else if(c==23)
    {
        return 2;
    }

return 0;

}


void block::show()
{
    if(state==1)
    cout<<to_show;
    else if(state==0)
       cout<<"*";
}

 block::block()
{
    state=0;
    to_show=0;
    presence_of_mine=0;
}

void block::change_state()
{
    state=1;
}

void block::inc_to_show()
{
    to_show++;
}
