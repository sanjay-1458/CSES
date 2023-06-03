#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define int long long
 
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
 
int power(int a, int b, int pow)
{
    a = a % pow;
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = ((res % pow) * (a % pow)) % pow;
        }
        a = ((a % pow) * (a % pow)) % pow;
        b >>= 1;
    }
    return res;
}
 
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int val = power(b, c, MOD - 1)%MOD;
        val = power(a, val, MOD)%MOD;
        cout << val << endl;
    }
    return 0;
}
