    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
            // cout<<"running for "<<t<<endl;
            int n;
            cin>>n;
            vector<int> vec(n);
            bool check=false;
            for(int i=0;i<n;i++)
            {
                cin>>vec[i];
            }
            sort(vec.begin(),vec.end());
            if(vec[0]==1)
            {
                cout<<2<<endl;
                
            }
            int p=vec[0];
            for(int i=2;i<=p;i++)
            {
                int g=__gcd(p,i);
                if(i==p)
                {
                    cout<<i+1<<endl;break;
                }
                else if(g==1)
                {
                    cout<<i<<endl;break;
                }
            }
        }
    }