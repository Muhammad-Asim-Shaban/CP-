	#include "bits/stdc++.h"
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define fio(name) freopen(name ".in","r",stdin);freopen(name ".out","w",stdout)
using namespace std;

int main() {
    fio("paint");
    IO;
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    cout << min((max(b, d) - min(a, c)), (b - a + d - c)) << endl;
    
    return 0;
}
