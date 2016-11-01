#include<cstdlib>
#include<cstdio>

#define max(a,b) a > b ? a : b;

using namespace std;

const int mid = 250;
int dp[30001][501];
int gem[30001];
int tmp,to,n,d,ans;

int main()
{
	scanf("%d%d",&n,&d);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&tmp);
		gem[tmp]++;
	}
	for (int i = 0; i <= 30000; ++i)
		for (int j = 0; j <= 500; ++j)
			dp[i][j] = -1000000;
	dp[d][mid] = gem[d];
	ans = gem[d];
	for (int i = d+1; i <= 30000; ++i)
		for (int j = 1; j <= 500; ++j)
		{
			tmp = j - mid;
			to = i - d - tmp;
			if (to >= d && to < i)
			{
				if (j-1>=1 && dp[to][j-1] >= 0) dp[i][j] = max(dp[i][j],dp[to][j-1]+gem[i]);
				if (j+1<=500 && dp[to][j+1] >=0) dp[i][j] = max(dp[i][j],dp[to][j+1]+gem[i]);
				if (dp[to][j] >= 0) dp[i][j] = max(dp[i][j],dp[to][j]+gem[i]);
				ans = max(ans,dp[i][j]);
			}
		}
	printf("%d\n",ans);
	return 0;
}
