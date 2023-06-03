#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define int long long
 
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int freq[1000009];

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;++i){
        int x; cin>>x;
        freq[x]++;
    }
    int ans=0;
    for(int i=1000000;i>=1;--i){
        int cnt=0;
        for(int j=i;j<=1000000;j+=i){
            cnt+=freq[j];
            if(cnt>=2){
                break;
            }
        }
        if(cnt>=2){
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
