#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;

 

void solve()
{
    int n,sum; cin>>n>>sum;
    vector<int> v(n,0);
    for(int i=0;i<n;++i) cin>>v[i];
    vector<int> dp(sum+1,0);
    dp[0]=1;
    for(int i=1;i<=sum;++i){
        for(int j=0;j<n;++j){
            if(i-v[j]>=0){
                dp[i]=(dp[i]+dp[i-v[j]])%mod;
            }
        }
    }
    cout<<dp[sum];
}
int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
