#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;

 
void fun(vector<int>&temp,int n){
    while(n>0){
        int rem=n%10;
        if(rem!=0) temp.push_back(rem);
        n=n/10;
    }
}

void solve()
{
    int n; cin>>n;
    vector<int> dp(n+1,1e7);
    dp[0]=0;
    for(int i=1;i<=n;++i){
        if(i<=9){
            dp[i]=1;
        }
        else{
            break;
        }
    }
    for(int i=10;i<=n;++i){
        vector<int> temp;
        fun(temp,i);
        for(int j=0;j<temp.size();++j){
            if(i-temp[j]>=0)
                dp[i]=min(dp[i],dp[i-temp[j]]+1);
        }
    }
    cout<<dp[n];
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
