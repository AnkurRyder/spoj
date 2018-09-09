#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define re(i, n) for(int i = 0; i < n; i++)
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define ren(i,a,b) for(int i = (a); i >= (b); i--)
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)

vector <ll> nn(100005 , 1);
vector <bool> vis(100005);

class graph
{
    int V;
    list < pii > *l;
    public:
        ll ans;
        graph(int v)
        {
            ans = 0;
            V = v;
            l = new list<pii> [V];
        }
        void ze()
        {
            re(i , V)
                vis[i] = false;
        }
        void add_edge(int u , int v , int weight)
        {
            l[u].push_back(make_pair(v , weight));
            l[v].push_back(make_pair(u , weight));
        }
        void dfs(int s)
        {
            vis[s] = true;
            for(pii i : l[s])
            {
                if(!vis[i.first])
                {
                    vis[i.first] = true;
                    dfs(i.first);
                    nn[s] += nn[i.first];
                }
            }
        }

        void last(int s)
        {
            vis[s] = true;
            nn[s]  = 1;
            for(pii i : l[s])
            {
                if(!vis[i.first])
                {
                    ans += 2*min(nn[i.first], V-nn[i.first])*(i.second);
                    last(i.first);
                }
            }
        }
};


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t , n , x, y ,z ,w;
    si(t);
    w = t;
    while(t--)
    {
        si(n);
        graph *g = new graph(n);
        re(i, n-1)
        {
            si(x);
            si(y);
            si(z);
            g->add_edge(x-1 , y-1 ,z);
        }
        g->dfs(0);
        g->ze();
        g->last(0);
        printf("%s","case #");
        printf("%d", w-t);
        printf("%s",": ");
        pl(g->ans);
        g->ze();
        delete(g);
    }
    return 0;
}
