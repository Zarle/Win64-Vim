#include<cstdio>

using namespace std;

int n;
int num[100010],cnt[100010];
int st[100010], ed[100010];

int main()
{
	//freopen("test0.in","r",stdin);
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&num[i]);
		++cnt[num[i]];
		if (!st[num[i]]) st[num[i]] = i;
		ed[num[i]] = i;
	}
	int mx = 0,pt;
	int f = n+1;
	for (int i = 1; i <= n; ++i)
		mx = mx > cnt[num[i]] ? mx : cnt[num[i]];
	for (int i = 1; i <= n; ++i)
		if (cnt[num[i]] == mx && ed[num[i]] - st[num[i]] + 1 < f)
		{
			f = ed[num[i]] - st[num[i]] + 1;
			pt = i;
		}
	printf("%d %d\n", st[num[pt]], ed[num[pt]]);
	return 0;
}
