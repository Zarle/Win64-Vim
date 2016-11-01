#include<cstdlib>
#include<cstdio>
#include<algorithm>

using namespace std;

int T,n,num[2000];

int main()
{
	scanf("%d",&T);
	for (int i = 1; i <= T; ++i)
	{
		scanf("%d",&n);
		for (int j = 1; j <= n; ++j)
			scanf("%d",&num[j]);
		sort(num+1,num+n+1);
		for (int j = 1; j <= n-1; ++j)
			printf("%d ",num[j]);
		printf("%d",num[n]);
		printf("\n");
	}
	return 0;
}
