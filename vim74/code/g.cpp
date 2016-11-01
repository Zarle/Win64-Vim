#include<cstdlib>
#include<cstdio>

using namespace std;

int n,cnt;
int num[100001],pos[100001];
int p[100001],pnum[100001];
bool pri[100001];
int ans,ans1[500001],ans2[500001];

void prime()
{
	pri[0] = pri[1] = true;
	for (int i = 2; i <= n; ++i)
	{
		pnum[i] = cnt;
		if (!pri[i]) p[++cnt] = i;
		for (int j = 1; j <= cnt; ++j)
		{
			if (p[j]*i > n) break;
			pri[p[j]*i] = true;
			if (! i % p[j]) break;
		}
	}
}

void change(int i,int j)
{
	int tmp = abs(i-j) + 1;
	if (!pri[tmp])
	{
		ans1[++ans] = i;
		ans2[ans] = j;
	}
	else
	{
		ans1[++ans] = i;
		ans2[ans] = i + p[pnum[tmp]] - 1;
		change(i + p[pnum[tmp]] - 1, j);
		ans1[++ans] = i;
		ans2[ans] = i + p[pnum[tmp]] - 1;
	}
}

int main()
{
	scanf("%d",&n);
	prime();
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&num[i]);
		pos[num[i]] = i;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (pos[i] == i) continue;
		change(i,pos[i]);
		num[pos[i]] = num[i];
		pos[num[i]] = pos[i];
		pos[i] = i, num[i] = i;
	}
	printf("%d\n",ans);
	for (int i = 1; i <= ans; ++i)
		printf("%d %d\n",ans1[i],ans2[i]);
	return 0;
}
