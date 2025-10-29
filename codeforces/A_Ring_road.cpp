#include<bits/stdc++.h>
using namespace std;
int a[1000010], b[1000010];
int main()
{
    int n;
    cin >> n;
    int s = 0, c = 0;
    for (int i = 1; i <= n; i++) {
		int x, y, z;
        cin >> x >> y >> z;
        if(a[x]){
        a[y] = 1, b[x] = 1, c += z;
        }else if(b[y]){
        a[y] = 1, b[x] = 1, c += z;
        }else{
        a[x] = 1, b[y] = 1;
    }
        s += z;
    }
    cout << min(c, s - c);

}

