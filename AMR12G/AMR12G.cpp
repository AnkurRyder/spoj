#include<iostream>

#include<vector>

#include<algorithm>

using namespace std;
bool cmp(int a,int b)
{
	return a < b;
}

int main()
{
	int k,sum=0;
	cin>>k;
	char c;
	for (int i = 0; i < k; ++i)
	{
		int m,n,a;
		cin>>m>>n>>a;
		std::vector<int> v(m,0);
		for (int j = 0; j < m; ++j)
		{
			for(int k=0; k < n; ++k)
			{
				cin>>c;
				if (c=='*')
				{
					v[j]++;
				}
			}
		}
		sort(v.begin(), v.end(),cmp);
		int indx= 0;
		while(v[indx]<=n/2 && a>0 && indx < m)
		{
			v[indx]= n - v[indx];
			indx++;
			a--;
		}
		if (a%2==1)
		{
			vector<int>::iterator it = min_element(v.begin(), v.end());
			*it = n-*it;
		}
		for( int j = 0; j< m; j++)
		{
			sum = sum + v[j];
		}
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
}
