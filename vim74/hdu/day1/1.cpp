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
	++cnt;
	edg[cnt].ed = ed;
	edg[cnt].v = v;
	edg[cnt].next = head[st];
	head[st] = edg + cnt;
}

bool cmp(edge t1,edge t2)
{
	return t1.v < t2.v;
}

void get()
{
	scanf("%lld%lld",&n,&m);
	ans = 0;
	sum = 0;
	for (long long i = 1; i <= m; ++i)
		scanf("%lld%lld%lld",&e[i].v1,&e[i].v2,&e[i].v);
	sort(e+1,e+m+1,cmp);
		cnt = 0;
	for (long long i = 0; i <= n; ++i)
		head[i] = NULL;
	memset(num,0,sizeof(num));
}


long long father(long long x)
{
	if (x != f[x]) f[x] = father(f[x]);
	else return x;
	return f[x];
}

void merge(long long x,long long y)
{
	f[father(y)] = father(x);
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

void kruskal()
{
	edge *pt = e+1;
	for (long long i = 1; i <= n; ++i)
		f[i] = i;
	for (long long i = 1; i <= n-1; ++i)
	{
		while  ((father(pt->v1) == father(pt->v2))) ++pt;
		ans += pt->v;
		add_edge(pt->v1,pt->v2,pt->v);
		add_edge(pt->v2,pt->v1,pt->v);
		merge(pt->v1,pt->v2);
	}
	dfs(1,-1);
}

int main()
{
	scanf("%lld",&T);
	while (T--)
	{
		get();
		kruskal();
		printf("%lld %.2lf\n",ans,((double)sum)/(n*(n-1))*2);
	}
	return 0;
}
