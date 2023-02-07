#include<iostream>
#include <random>
#include<fstream>
#include<string>
#include <cstdlib>
#include <ctime>
using namespace std;
class question
{

    int score1;
    int score2;
    int n;
    string *questions;
    string **hint;
    int *answer;
    int * ran;
    public:
        int getn();
        int getscore1();
        int getscore2();
        string* getquestions();
        string** gethint();
        int *getanswer();
        int getcuranswer(int i);
        void setn(int x);
        void setscore1(int x);
        void setscore2(int x);
        void setquestion(string *_question,int n1);
        void sethint(string **_hint,int n1);
        void setanswer(int* _answer,int n1);
        int randomques(int i);
        question();
        ~question()
        {
            n=0;
            score1=0;
            score2=0;
            delete[]ran;
            delete []questions;
            ran=NULL;
            questions=NULL;
            delete []hint;
            delete []answer;
            hint=NULL;
            answer=NULL;
        }
    void print(int x,int i);
};
class Trivia
{
    question q;
    public:
    Trivia(string filename);
    void rungame();
};