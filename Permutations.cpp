#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    if(n<=3){
        if(n==1){
            cout<<1<<endl;
        }
        else{
            cout<<"NO SOLUTION"<<endl;
        }
        return 0;
    }
    vector<int> arr;
    int i=2,c=n/2;
    while(c--){
        arr.push_back(i);
        i+=2;
    }
    if(n%2==0){
        c=n/2;
    }
    else{
        c=n/2+1;
    }
    i=1;
    while(c--){
        arr.push_back(i);
        i+=2;
    }
    for(auto e:arr){
        cout<<e<<" ";
    }cout<<endl;
}
