#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;

 

void solve()
{
    int n,sum; cin>>n>>sum;
    vector<int> v(n,0);
    for(int i=0;i<n;++i) cin>>v[i];
    vector<int> dp(sum+1,1e9);
    dp[0]=0;
    for(int i=1;i<=sum;++i){
        for(int j=0;j<n;++j){
            if(v[j]<=i){
                dp[i]=min(dp[i],dp[i-v[j]]+1);
            }
        }
    }
    cout<<(dp[sum]<1e9?dp[sum]:-1)<<endl;
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
