#include <iostream>
#include <string>

int inter(char);

using namespace std;

int main()
{
    string roman;
    int decimal=0,len;

    cout<<" enter roman numeral ";
    cin>>roman;

   // cout<<inter(roman[1]);


    len=roman.length();

    for(int i=0;i<len-1;i++)
    {

       if(inter(roman[i])>=inter(roman[i+1]))
           { decimal+=inter(roman[i]); }
       else if (inter(roman[i])<inter(roman[i+1]))
       {
         decimal+=(inter(roman[i+1])-inter(roman[i]));
         i+=1;
       }
    }

    if (inter(roman[len-1])<=inter(roman[len-2]))
        decimal+=inter(roman[len-1]);

        cout<<" decimal is "<<decimal;



    return 0;
}


int inter(char a)
{
    int s;

    switch(a)
    {
        case 'I': s=1; break;
        case 'V': s=5; break;
        case 'X': s=10; break;
        case 'L': s=50; break;
        case 'C': s=100; break;
        case 'D': s=500; break;
        case 'M': s=1000; break;
    }

    return s;
}