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

int n;

int rec(vector<vector<bool> > v ,int r, int c , int count)
{
	if(r > n-1 || c > n-1 || r < 0 || c < 0)
		return count;
	if(!v[r][c])
		return count;
	v[r][c] = 0;
	count--;
	int u = rec(v , r-2 , c-1 , count);
	int d = rec(v , r-2 , c+1 , count);
	int l = rec(v , r-1 , c-2 , count);
	int ri = rec(v , r-1 , c+2 , count);
	int ul = rec(v , r+2 , c-1 , count);
	int ur = rec(v , r+2 , c+1 , count);
	int dl = rec(v , r+1 , c+2 , count);
	int dr = rec(v , r+1 , c-2 , count);
	return min(u ,min(d , min(l , min(ri, min(ul , min(ur , min(dl ,dr)))))));
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x;
	si(n);
	int count = 0;
	vector<vector<bool> > v(n , vector<bool>(n,0));
	re(i , n)
	{
		re(j , n)
		{
			si(x);
			if(x)
				count++;
			v[i][j] = x;
		}
	}
	int start;
	re(i , n)
	{
		if(v[0][i])
		{
			start = i;
			break;
		}
	}
	pi(rec(v , 0 , start , count));
	return 0;
}