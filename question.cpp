#include"question.h"
int question::getn()
{
    return n;
}
void question::setn(int x)
{
    n=x;
}
int question::getscore1()
{
    return score1;
}
int question::getscore2()
{
    return score2;
}
string* question::getquestions()
{
    return questions;
}
string** question::gethint()
{
    return hint;
}
int* question::getanswer()
{
    return answer;
}
int question::getcuranswer(int i)
{
    return answer[i];
}
void question::setscore1(int x)
{
    score1= x;
}
void question::setscore2(int x)
{
    score2=x;
}
void question::setquestion(string *_question,int n1)
{
    questions=new string [n1];
    n=n1;
    for(int i=0;i<n1;i++)
    {
        questions[i]=_question[i];
    }

}
void question::sethint(string **_hint,int n1)
{
    hint=new string*[n1];
    n=n1;
    for(int k=0;k<n1;k++)
    {
        hint[k]= new string[4];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
        {
            hint[i][j]=_hint[i][j];
        }
    }
}
void question::setanswer(int* _answer,int n1)
{
    answer=new int[n1];
    n=n1;
    for(int i=0;i<n1;i++)
    {
        answer[i]=_answer[i];
    }
}
question::question()
{
    n=0;
    questions=NULL;
    hint=NULL;
    answer=NULL;
    ran=new int[10];
    for(int i=0;i<10;i++)
    {
        ran[i]=-1;
    }
}
void question::print(int x,int i)
{
    cout<<"QUESTION "<<x<<": "<<questions[i]<<"\n";
    cout<<"1. "<<hint[i][0]<<"\n";
    cout<<"2. "<<hint[i][1]<<"\n";
    cout<<"3. "<<hint[i][2]<<"\n";
    cout<<"4. "<<hint[i][3]<<"\n";
    cout<<"\n";
}
int question:: randomques(int i)
{
    int j=-1,e=0;
    srand(static_cast <unsigned int> (time(0)));
    int q1= rand()%(n-1)+0;
    while(j==-1)
    {
        for(int k=0;k<10;k++)
        {
            if(q1==ran[k])
            {
                e=1;
            }
        }
        if(e==1)
        {
            q1=rand()%(n-1)+0;
        }
        else if (e==0) j=0;
        e=0;
    }
    ran[i]=q1;
    return q1;

}
Trivia::Trivia(string filename)
{
    int i=0,j=0;
    int n=0;
    string q1,h,a;
    ifstream in;
    in.open(filename);
    if(in.is_open())
    {
        while(!in.eof())
        {
            getline(in,q1);
            getline(in,h);
            getline(in,h);
            getline(in,h);
            getline(in,h);
            in>>a;
            n++;
            in.ignore();
        }
        in.close();
        string *questions =new string [n];
        string **hint=new string*[n];
        for(int k=0;k<n;k++)
        {
            hint[k]= new string[4];
        }
        int *answer=new int [n];

        in.open(filename);
        while(!in.eof())
        {
            getline(in,questions[i]);
            getline(in,hint[i][j]);
            j++;
            getline(in,hint[i][j]);
            j++;
            getline(in,hint[i][j]);
            j++;
            getline(in,hint[i][j]);
            in>>answer[i];
            i++;
            in.ignore();
            j=0;
        }
        q.setn(n);
        q.setquestion(questions,n);
        q.sethint(hint,n);
        q.setanswer(answer,n);
        delete questions;
        delete hint;
        delete answer;
    }
    else{
        cout<<"Can't not open file!\n";
    }
    in.close();
}
void Trivia::rungame()
{
    int score1=0;
    int score2=0;
    int rep;
    srand(static_cast <unsigned int> (time(0)));
    //srand(static_cast <unsigned int> (time(0)));
    cout<<"Welcome to trivia game!\n";
    cout<<"Player 1! Lets start the game!\n\n";
    for(int i=0;i<5;i++)
    {
        int q1= q.randomques(i);
        q.print(i+1,q1);
        cout<<"Enter a answer: ";
        cin>>rep;
        while(rep<1||rep>4)
        {
            cout<<"Invalid answer please enter the answer again!\n";
            cout<<"Enter a answer: ";
            cin>>rep;
        }
        if(rep==q.getcuranswer(q1))
        {
            cout<<"Congrats! Player 1 gains a point.\n";
            score1++;
            cout<<"Score: "<<score1<<"\n\n";
        }
        else
        {
            cout<<"The answers is incorrect T__T\n\n";
        }
    }
    cout<<"\nIt's your turn player 2! Lets start the game!\n";
    for(int i=0;i<5;i++)
    {
        int q1= q.randomques(i+5);
        q.print(i+1,q1);
        cout<<"Enter a answer: ";
        cin>>rep;
        while(rep<1||rep>4)
        {
            cout<<"Invalid answer please enter the answer again!\n";
            cout<<"Enter a answer: ";
            cin>>rep;
        }
        if(rep==q.getcuranswer(q1))
        {
            cout<<"Congrats! Player 2 gains a point.\n";
            score2++;
            cout<<"Score: "<<score2<<"\n\n";
        }
        else
        {
            cout<<"The answers is incorrect T__T\n\n";
        }
    }
    cout<<"Two players score\n";
    cout<<"Players 1: "<<score1<<"\n";
    cout<<"Players 2: "<<score2<<"\n";
    if(score2>score1)
    {
        cout<<"Players 2 you're the winner. Congrats!\n";
    }
    else if(score1<score2)
    {
        cout<<"Players 2 you're the winner. Congrats!\n";
    }
    else if(score1==score2)
    {
        cout<<"This is a draw here. Congrats to two players!\n";
    }
}