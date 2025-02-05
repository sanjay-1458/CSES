#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define trav(a, x) for (const auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr)

typedef long long ll;
typedef std::pair<ll, ll> pi;
typedef std::vector<ll> vi;
typedef std::vector<vi> vvi;
typedef std::vector<pi> vpi;
typedef std::string si;

template <typename T>
void _(T &&value)
{
    std::cout << value << std::endl;
}

template <typename T, typename... Args>
void _(T &&value, Args &&...args)
{
    std::cout << value << " ";
    _(std::forward<Args>(args)...);
}

template <typename T>
std::istream &operator>>(std::istream &istream, std::vector<T> &v)
{
    for (auto &it : v)
    {
        istream >> it;
    }
    return istream;
}

template <typename T>
std::ostream &operator<<(std::ostream &ostream, const std::vector<T> &c)
{
    for (const auto &it : c)
    {
        ostream << it << " ";
    }
    return ostream;
}

using namespace std;

const int MOD = 998244353;

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

ll qexp(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b % 2)
            res = res * a;
        a = a * a;
        b /= 2;
    }
    return res;
}
ll log(ll a, ll b)
{
    return log2(a) / log2(b);
}
ll modPow(ll base, ll exponent, ll mod)
{
    ll result = 1;
    base = base % mod;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % mod;
        exponent = exponent >> 1;
        base = (base * base) % mod;
    }
    return result;
}

ll modInverse(ll a, ll m)
{
    return modPow(a, m - 2, m);
}

ll nCr(ll n, ll r)
{
    if (r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;

    ll ans = 1;

    for (int i = 1; i <= r; ++i)
    {
        ans = ans * (n - r + i) % MOD;
        ans = ans * modInverse(i, MOD) % MOD;
    }

    return ans;
}
ll max(ll a, ll b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
ll sum(ll n)
{
    return (n * (n + 1)) / 2;
}

class Compare
{
public:
    bool operator()(int a, int b)
    {
        if (a)
        {
            return true;
        }
        return false;
    }
};


void dfs(int x,int y,vector<vector<char>> &v){
    int n=v.size(),m=v[0].size();
    v[x][y]='#';
    int dr[]={0,0,-1,1};
    int dc[]={-1,1,0,0};
    rep(i,0,4){
        int nx=x+dr[i],ny=y+dc[i];
        if(nx>=0 && nx<n && ny>=0 && ny<m && v[nx][ny]=='.'){
            dfs(nx,ny,v);
        }
    }
}

void solve()
{
    int n,m; cin>>n>>m;
    vector<vector<char>> v(n,vector<char>(m));
    pair<int,int> start,end;
    rep(i,0,n){
        rep(j,0,m){
            cin>>v[i][j];
            if(v[i][j]=='A'){
                start={i,j};
            }
            if(v[i][j]=='B'){
                end={i,j};
            }
        }
    }
    vector<vector<int>> dist(n,vector<int>(m,1e9));
    vector<vector<pair<int,int>>> par(n,vector<pair<int,int>>(m));
    
    priority_queue<pair<int,pair<pair<int,int>,pair<int,int>>>,vector<pair<int,pair<pair<int,int>,pair<int,int>>>>,greater<pair<int,pair<pair<int,int>,pair<int,int>>>>> pq;
    dist[start.first][start.second]=0;
    par[start.first][start.second]=start;
    pq.push({0,{start,start}});
    int dr[]={0,0,-1,1};
    int dc[]={-1,1,0,0};
    while(!pq.empty()){
        auto node=pq.top();
        pq.pop();
        int dist_u=node.first;
        pair<int,int> node_u=node.second.first;
        pair<int,int> par_u=node.second.second;
        if(node_u==end){
            break;
        }
        for(int i=0;i<4;++i){
            pair<int,int> nbr={node_u.first+dr[i],node_u.second+dc[i]};
            if(nbr.first>=0 && nbr.first<n && nbr.second>=0 && nbr.second<m && v[nbr.first][nbr.second]!='#'){
                if(dist_u+1<dist[nbr.first][nbr.second]){
                    dist[nbr.first][nbr.second]=dist_u+1;
                    par[nbr.first][nbr.second]=node_u;
                    pq.push({dist_u+1,{nbr,node_u}});
                }
            }
        }
    }
    if(dist[end.first][end.second]==1e9){
        _("NO");
        return;
    }
    _("YES");
    _(dist[end.first][end.second]);
    pair<int,int> temp=end;
    string ans="";
    while(temp!=par[temp.first][temp.second]){
        pair<int,int> par_t=par[temp.first][temp.second];
        if(par_t.first==temp.first-1 && par_t.second==temp.second){
            ans+='D';
        }
        else
        if(par_t.first==temp.first && par_t.second==temp.second+1){
            ans+='L';
        }
        else
        if(par_t.first==temp.first+1 && par_t.second==temp.second){
            ans+='U';
        }
        else{
            ans+='R';
        }
        temp=par_t;
    }
    reverse(all(ans));
    _(ans);
    
}


int main()
{
    fast_io;

    int test = 1;
    // cin >> test;
    for (int test_cases = 1; test_cases <= test; ++test_cases)
    {
        solve();
    }

    return 0;
}
