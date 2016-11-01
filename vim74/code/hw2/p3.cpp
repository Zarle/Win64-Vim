//MST

#include<cstdio>
#include<cstdlib>

#define min(a,b) (a < b ? a : b)
struct edge
{
	int v,ed;
	edge* next;
}*head[1010],e[100010];

bool vis[1010];
int dist[1010];
int cnt;
int ans,s,t,c,n,m;

void add_edge(int st,int ed,int v)
{
	e[++cnt].v = v;
	e[cnt].ed = ed;
	e[cnt].next = head[st];
	head[st] = e + cnt;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d%d",&s,&t,&c);
		add_edge(s,t,c);
		add_edge(t,s,c);
	}
	for (int i = 0; i <= n; ++i)
		dist[i] = 0x3f3f3f3f;
	cnt = 0;
	dist[1] = 0;
	while (cnt != n)
	{
		int f = 0;
		for (int i = 1; i <= n; ++i)
			if (dist[i] < dist[f] && !vis[i]) f = i;
		if (dist[f] == 0x3f3f3f3f) //²»ÁªÍ¨
		{
			printf("No Answer!\n");
			return 0;
		}
		ans += dist[f];
		vis[f] = 1;
		++cnt;
		for (edge *pt = head[f]; pt; pt = pt->next)
			dist[pt->ed] = min(dist[pt->ed],pt->v);
	}
	printf("%d\n",ans);
	return 0;
}
