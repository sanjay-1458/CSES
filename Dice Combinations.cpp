#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


const int mod=1e9+7;
ll fun(int n,vector<ll>&dp){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(dp[n]!=-1) return dp[n];
    ll cnt=0;
    for(int i=1;i<=6;++i){
        cnt+=(fun(n-i,dp)%mod);
    }
    return dp[n]=(cnt)%mod;
}


void solve()
{
    int n; cin>>n;
    vector<ll> dp(n+1,-1);
    cout<< fun(n,dp)<<endl;
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
