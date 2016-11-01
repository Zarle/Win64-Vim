#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int T,n;
long long key[310],v[310];
long long f[310][310];
long long dp[310];

long long gcd(long long a,long long b)
{
	return b==0?a:gcd(b,a%b);
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		memset(f,0,sizeof(f));
		memset(dp,0,sizeof(dp));
		scanf("%d",&n);
		for (int i = 1; i <= n; ++i)
			scanf("%lld",&key[i]);
		for (int i = 1; i <= n ; ++i)
			scanf("%lld",&v[i]);
		for (int l = 1; l < n; l += 2)
			for (int i = 1; i + l <= n; ++i)
			{
				int j = i + l;
				if (i+1 == j)
				{
					if (gcd(key[i],key[j]) != 1)
						f[i][j] = v[i]+v[j];
					continue;
				}
				for (int k = i+1; k <= j; k += 2)
					if (f[i][k] == 0 || f[k+1][j] == 0) continue;
					else f[i][j] = max(f[i][j],f[i][k]+f[k+1][j]);
				if (gcd(key[i],key[j]) != 1 && f[i+1][j-1] != 0) f[i][j] = max(f[i][j],f[i+1][j-1]+v[i]+v[j]);
			}
		for (int i = 1; i <= n; ++i)
		{
			dp[i] = dp[i-1];
			for (int j = 1; j < i; ++j)
				dp[i] = max(dp[i],dp[j-1]+f[j][i]);
		}
		printf("%lld\n",dp[n]);
	}
	return 0;
}
