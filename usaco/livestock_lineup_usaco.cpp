#include<bits/stdc++.h>
using namespace std;
const vector<string>COWS=[]()
{
    vector<string>tmp{"Bessie", "Buttercup", "Belinda", "Beatrice",
	                   "Bella",  "Blue",      "Betsy",   "Sue"};
    sort(tmp.begin(),tmp.end());
    return tmp;
}();
int main()
{
    ifstream fin("lineup.in");
    ofstream fout("lineup.out");
    map<string,int>cow_inds;
    for(int i=0;i<COWS.size();i++)
    {
        cow_inds[COWS[i]]=i;
    }
    int n;
    fin>>n;
    vector<vector<int>>neighbors(COWS.size());  //adjacency list
    for(int r=0;r<n;r++)
    {
        string cow1;
        string cow2;
        string trash;
        fin>>cow1>>trash>>trash>>trash>>trash>>cow2;
        int c1=cow_inds[cow1];
        int c2=cow_inds[cow2];
        neighbors[c1].push_back(c2);
        neighbors[c2].push_back(c1);
    }
    vector<int>order;
    vector<bool>added(COWS.size(),false);
    for(int c=0;c<COWS.size();c++)
    {
        if(!added[c]&&neighbors[c].size()<=1)
        {
            added[c]=true;
            order.push_back(c);
            if(neighbors[c].size()==1)
            {
                int prev=c;
                int at=neighbors[c][0];
                while(neighbors[at].size()==2)
                {
                    added[at]=true;
                    order.push_back(at);
                    int a=neighbors[at][0];
                    int b=neighbors[at][1];
                    int temp_at=a==prev?b:a;
                    prev=at;
                    at=temp_at;
                }
                added[at]=true;
                order.push_back(at);
            }
        }
    }
    for(int c:order)
    {
        fout<<COWS[c]<<endl;
    }
}