#include<bits/stdc++.h>
using namespace std;
#define ll long long
class segmenttree
{
    private:
    vector<ll> tree;
    vector<ll> arr;
    ll n;
    void build(ll idx,ll l,ll r)
    {
        if(l==r)
        {
            tree[idx]=arr[l];
            return;
        }
        ll mid=(l+r)/2;
        build(2*idx+1,l,mid);
        build(2*idx+2,mid+1,r);
        tree[idx]=min(tree[2*idx+1],tree[2*idx+2]);
    }
    ll query(ll idx,ll l,ll r,ll ql,ll qr)
    {
        if(qr<l||ql>r) return INT_MAX;
        if(l>=ql&&r<=qr)
        {
            return tree[idx];
        }
        ll m=(l+r)/2;
        ll left=query(2*idx+1,l,m,ql,qr);
        ll right=query(2*idx+2,m+1,r,ql,qr);
        return min(left,right);
    }
    void update(ll idx,ll l,ll r,ll pos,ll val)
    {
        if(l==r)
        {
            arr[pos]=val;
            tree[idx]=val;
            return;
        }
        ll m=(l+r)/2;
        if(pos<=m)
        {
            update(2*idx+1,l,m,pos,val);
        }
        else
        {
            update(2*idx+2,m+1,r,pos,val);
        }
        tree[idx]=min(tree[2*idx+1],tree[2*idx+2]);
    }
    public:
    segmenttree(){}
    segmenttree(vector<ll> input)
    {
        n=input.size();
        //arr.resize(n);
        arr=input;
        tree.resize(4*n);
        build(0,0,n-1);
    }
    ll getsum(ll ql,ll qr)
    {
        return query(0,0,n-1,ql,qr);
    }
    void getupdate(ll pos,ll val)
    {
        update(0,0,n-1,pos,val);
    }
};
int main()
{
    ll n,q;
    cin>>n>>q;
    vector<ll> input(n);
    
    for(ll i=0;i<n;i++)
    {
        cin>>input[i];
    }
    segmenttree st(input);
    while(q--)
    {
        ll a;
        cin>>a;
        if(a==1)
        {   
            ll k,u;
            cin>>k>>u;
            k--;
            st.getupdate(k,u);
        }
        else 
        {
            ll k,u;
            cin>>k>>u;
            k--;
            u--;
            cout<<st.getsum(k,u)<<endl;
        }
    }
}