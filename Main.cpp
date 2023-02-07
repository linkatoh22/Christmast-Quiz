#include<iostream>
#include"question.h"
int main()
{
    char to='Y';
    while(to=='Y')
    {
    Trivia a("question.txt");
    a.rungame();
    cout<<"Do you want to play again (Y to continue N to exit): ";
    cin>>to;
    cout<<"\n\n";
    }
    return 0;
}