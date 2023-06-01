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
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int val = arr[0], ans = 0;
    for (int i = 1; i < n; ++i)
    {
        int diff = val - arr[i];
        if (diff > 0)
        {
            ans += diff;
        }
        else
        {
            val = arr[i];
        }
    }
    cout << ans << endl;
}
