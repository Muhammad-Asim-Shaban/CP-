#include<iostream>
using namespace std;
int main()
{
    string sent="aaaab";
    string pattern="aaab";
    if(pattern.length()==0)
    {
        cout<<"Not present inside the sentence"<<endl;
        return 0;
    }
    int it=0;
    for(int i=0;i<sent.length();i++)
    {
        if(sent[i]==pattern[it])
        {
            it++;
        }
        else
        {
            it=0;
            i--;
        }
        if(it==pattern.length())
        {
            cout<<"Present inside the string"<<endl;
            return 0;
        }
    }
    cout<<"Not present inside the sentence"<<endl;

}