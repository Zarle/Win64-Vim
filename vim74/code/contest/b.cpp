#include <cstdio>

#define abs(a) ((a)<0 ? -(a) :a)

using namespace std;

int n,T,pt,now,ans;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		ans = 0;
		scanf("%d",&n);
		scanf("%d",&pt);
		for (int i = 2; i <= n; ++i)
		{
			scanf("%d",&now);
			ans += abs(4-pt);
			pt = now - (4-pt);
		}
		printf("%d\n",ans);
	}
	return 0;
}
