#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long n,m,T,cnt;
long long ans,sum;
long long f[100010];
long long num[100010];


struct edge
{
	long long v1,v2,v;
}e[1000010];

struct ee
{
	long long ed,v;
	ee* next;
}edg[200020],*head[100010];

void add_edge(long long st,long long ed,long long v)
{
	edg[++cnt].ed = ed;
	edg[cnt].v = v;
	edg[cnt].next = head[st];
	head[st] = edg + cnt;
}

long long dfs(long long now,long long ft)
{
	for (ee *pt = head[now]; pt; pt=pt->next)
		if (pt->ed != ft)
		{
			long long cn = dfs(pt->ed,now);
			num[now] += cn;
			sum += pt->v*cn*(n-cn);
		}
	return num[now]+1;
}

void get()
{
	cnt = 0;
	memset(num,0,sizeof(num));
	scanf("%lld",&n);
	for (long long i = 0; i <= n; ++i)
		head[i] = NULL;
	ans = 0;
	sum = 0;
	for (long long i = 1; i < n; ++i)
	{
		scanf("%lld%lld%lld",&e[i].v1,&e[i].v2,&e[i].v);
		edge *pt = e+i;
		add_edge(pt->v1,pt->v2,pt->v);
		add_edge(pt->v2,pt->v1,pt->v);
		
	}
	dfs(1,-1);
}


int main()
{
	scanf("%lld",&T);
	while (T--)
	{
		get();
		printf("%lf\n",((double)sum)/(n*(n-1))*2);
	}
	return 0;
}
