#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200000;       // CSES limit
long long a[MAXN+5];
long long seg[4*MAXN+5];

void build(int index,int low,int high) {
    if(low==high) {
        seg[index]=a[low];
        return;
    }
    int mid=(low+high)/2;
    build(2*index+1,low,mid);
    build(2*index+2,mid+1,high);
    seg[index]=min(seg[2*index+1],seg[2*index+2]);
}

long long query(int index,int low,int high,int l,int r) {
    if(low>=l&&high<=r) return seg[index];
    if(high<l||low>r) return INT_MAX;
    int mid=(low+high)/2;
    long long left=query(2*index+1,low,mid,l,r);
    long long right=query(2*index+2,mid+1,high,l,r);
    return min(left,right);
}

void update(int index,int low,int high,int pos,long long val) {
    if(low==high) {
        a[pos]=val;
        seg[index]=val;
        return;
    }
    int mid=(low+high)/2;
    if(pos<=mid) update(2*index+1,low,mid,pos,val);
    else update(2*index+2,mid+1,high,pos,val);
    seg[index]=min(seg[2*index+1],seg[2*index+2]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++) cin>>a[i];
    build(0,0,n-1);
    while(q--) {
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        cout<<query(0,0,n-1,l,r)<<endl;
    }
}
