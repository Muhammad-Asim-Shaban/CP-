#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,t;
    cin>>n>>t;
    int arr[n];
    for(long long i=0;i<n-1;i++)
    {
        cin>>arr[i];
    }
    long long cur=1;
    do
    {
        cur=cur+arr[cur-1];
        if(cur==t)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    } while (cur<n);
    cout<<"NO"<<endl;
}