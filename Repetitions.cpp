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

    string s;
    cin >> s;
    int ans = 0, c = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (i == 0 || s[i] != s[i - 1])
            c = 1;
        else
            c++;
        ans = max(ans, c);
    }
    cout << ans << endl;
}
