#include<cstdlib>
#include<cstdio>

using namespace std;

int n,jus,sum,ans = 0,s;
int v[51];
bool f[510000];

int main()
{
	scanf("%d%d",&n,&jus);
	f[0] = true;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&v[i]);
		sum += v[i];
		for (int j = sum; j >= v[i]; j--)
			f[j] |= f[j-v[i]];
	}
	while (true)
	{
		int i;
		for (i = ans + jus; i >= ans; --i)
			if (i <= sum && f[i]) break;
		if (i == ans) break;
		else ans = i, s++;
	}
	printf("%d %d\n",ans,s);
	return 0;
}