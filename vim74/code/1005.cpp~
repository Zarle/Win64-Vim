#include<cstdlib>
#include<cstdio>
#include<algorithm>

using namespace std;

int T,m,n,q;
int ft[20010];
int lamp[20010];

struct edge
{
	int x,y,d;
}e[100010];

struct qq
{
	int v,num,ans;
}query[5010];

bool cmp(edge x,edge y)
{
	return x.d < y.d;
}

bool cmp1(qq x, qq y)
{
	return x.v < y.v;
}

bool cmp2(qq x, qq y)
{
	return x.num < y.num;
}

int find(int x)
{
	int tmp = x;
	while (tmp != ft[tmp])
		tmp = ft[tmp];
	int tt;
	while (ft[x]!=tmp)
	{
		tt = ft[x];
		ft[x] = tmp;
		x = tt;
	}
	return tmp;
}

int uni(int x, int y)
{
	int fx = find(x), fy = find(y);
	if (fx != fy)
	{
		ft[fy] = fx;
		int tmp = lamp[fx]*lamp[fy];
		lamp[fx] += lamp[fy];
		return tmp;
	}
	else return 0;
}

void init()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i = 1; i <= n; ++i)
	{
		ft[i] = i;
		lamp[i] = 1;
	}
	for (int i = 1; i <= m; ++i)
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].d);
	sort(e+1,e+m+1,cmp);
	for (int i = 1; i <= q; ++i)
	{
		scanf("%d",&query[i].v);
		query[i].num = i;
	}
	sort(query+1,query+q+1,cmp1);
	query[0].ans = 0;
}

void deal()
{
	int cnt = 1;
	for (int i = 1; i <= q; ++i)
	{
		query[i].ans = query[i-1].ans;
		while (e[cnt].d <= query[i].v && cnt <= m)
		{
			query[i].ans += 2*uni(e[cnt].x,e[cnt].y);
			++cnt;
		}
	}
}

void print()
{
	sort(query+1,query+q+1,cmp2);
	for (int i = 1; i <= q; ++i)
		printf("%d\n",query[i].ans);
}

int main()
{
	scanf("%d",&T);
	for (int i = 1; i <= T; ++i)
	{
		init();
		deal();
		print();
	}
	return 0;
}
