#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
	long long n,t,i,j,b,c;
	cin>>t;
	while(t--){
		cin>>n;
		b=0; c=1;
		for(i=0;i<n;i++){
			cin>>j;
			if(j==1) b++;
			if(j==0) c*=2;
		}
		cout<<b*c<<endl;
	}
}