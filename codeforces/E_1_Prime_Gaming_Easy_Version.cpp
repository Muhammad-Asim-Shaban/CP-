#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int MOD = 1000000007;

using u32 = uint32_t;
using u64 = uint64_t;
using i16 = int16_t;
using u8 = uint8_t;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin>>T)) return 0;
    while(T--){
        int n,m; cin>>n>>m;
        int k; cin>>k;
        vector<int> c(k);
        for(int i=0;i<k;++i) cin>>c[i];

        if(m==1){
            cout<<1<<"\n";
            continue;
        }
        const int Nmask = 1<<n;

        vector<int> popc(Nmask);
        vector<vector<int>> masks_by_pc(n+1);
        for(int mask=1; mask<Nmask; ++mask){
            int pc = __builtin_popcount((unsigned)mask);
            popc[mask] = pc;
            masks_by_pc[pc].push_back(mask);
        }
        vector<i16> pos_of_bit((size_t)Nmask * n, -1);
        for(int mask=1; mask<Nmask; ++mask){
            int tmp = mask;
            int t = 0;
            while(tmp){
                int bit = __builtin_ctz((unsigned)tmp);
                pos_of_bit[(size_t)mask * n + t] = (i16)bit;
                ++t;
                tmp &= tmp - 1;
            }
        }
        vector<vector<int>> moves(n+1);
        for(int p=1;p<=n;++p){
            for(int idx : c) if(idx <= p) moves[p].push_back(idx);
        }

        vector<u8> dp(Nmask);

        int64 count2 = 0;
        const int FULL = (1<<n) - 1;
        const int total_assign = 1<<n;

    
        for(int assign=0; assign<total_assign; ++assign){
            for(int mask : masks_by_pc[1]){
                int idx = __builtin_ctz((unsigned)mask);
                dp[mask] = (u8)((assign >> idx) & 1);
            }
            for(int p=2; p<=n; ++p){
                const auto &mv = moves[p];
                if(mv.empty()){
                    for(int mask : masks_by_pc[p]) dp[mask] = 0;
                    continue;
                }
                bool alice_turn = (((n - p) & 1) == 0); 

                if(alice_turn){
                    for(int mask : masks_by_pc[p]){
                        u8 res = 0;
                        for(int ci : mv){
                            int posIndex = ci - 1;
                            i16 bit = pos_of_bit[(size_t)mask * n + posIndex];
                            int child = mask & ~(1<<bit);
                            if(dp[child]){
                                res = 1;
                                break;
                            }
                        }
                        dp[mask] = res;
                    }
                } else {
                    for(int mask : masks_by_pc[p]){
                        u8 res = 1;
                        for(int ci : mv){
                            int posIndex = ci - 1;
                            i16 bit = pos_of_bit[(size_t)mask * n + posIndex];
                            int child = mask & ~(1<<bit);
                            if(!dp[child]){
                                res = 0;
                                break;
                            }
                        }
                        dp[mask] = res;
                    }
                }
            }
            count2 += dp[FULL];
        }
        int64 pow2n = (1LL<<n) % MOD;
        int64 ans = (pow2n + (count2 % MOD)) % MOD;
        cout << ans << '\n';
    }
    return 0;
}
