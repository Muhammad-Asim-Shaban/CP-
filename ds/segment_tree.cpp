#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct item{
    int m,c;

};
struct segtree
{
    //all the sums code.....
    int size;
    vector<int>sums;
    item NEUTRAL_ELEMENT={INT_MAX,0};
    int size;
    vector<item> sums;
    //vector<item> values;
    item single(int v)
    {
        return {v,1};
    }
    item merge(item a, item b)
    {
        if(a.m<b.m) return a;
        if(a.m>b.m) return b;
        return {a.m,a.c+b.c};
    }
    void init(int n)
    {
        size=1;
        while(size<n) size*=2;
        sums.resize(2*size);
        //values.assign(2*size,0);
        //cout<<"size of sum:"<<sums.size()<<endl;
        //cout<<"size variable is "<<size<<endl;
    }
    void build(vector<int> &a,int x, int lx, int rx)
    {
        if(rx-lx==1)
        {
            if(lx<a.size())
            {
                sums[x]=single(a[lx]);
            }
            return;
        }
        int m=(lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        sums[x]=merge(sums[2*x+1],sums[2*x+2]);
    }

    void build(vector<int> &a)
    {
        build(a,0,0, size);
    }
    void set(int i,int v,int x,int lx,int rx)
    {
        if(rx-lx==1)
        {
            sums[x]=single(v);
            return;
        }
        int m=(lx+rx)/2;
        if(i<m)
        {
            set(i,v,2*x+1,lx,m);
        }
        else
        {
            set(i,v,2*x+2,m,rx);
        }
        sums[x]=merge(sums[2*x+1],sums[2*x+2]);
    }
    void set(int i,int v)
    {
        set(i,v,0,0,size);
    }
    // ll sum(int l,int r,int x,int lx,int rx)
    // {
    //     if(lx>=r || l>=rx)
    //     {
    //         return 0;
    //     }
    //     if(lx>=l && rx<=r) return sums[x];
    //     int m=(lx+rx)/2;
    //     ll s1=sum(l,r,2*x+1,lx,m);
    //     ll s2=sum(l,r,2*x+2,m,rx);
    //     return s1+s2;
    // }   
    // ll sum(int l,int r)
    // {
    //     return sum(l,r,0,0,size);
    // }



    item calc(int l,int r,int x,int lx,int rx)
    {
        if(lx>=r || l>=rx)
        {
            return NEUTRAL_ELEMENT;
        }
        if(lx>=l && rx<=r) return sums[x];
        int m=(lx+rx)/2;
        item s1=calc(l,r,2*x+1,lx,m);
        item s2=calc(l,r,2*x+2,m,rx);
        return merge(s1,s2);
    }   
    item calc(int l,int r)
    {
        return calc(l,r,0,0,size);
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    segtree st;
    st.init(n);
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    st.build(a);
    while(m--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int i,v;
            cin>>i>>v;
            st.set(i,v);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            auto res=st.calc(l,r);
            cout<<res.m <<" "<<res.c<<endl;
        }
    }
}