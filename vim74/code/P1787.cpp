#include<cstdlib>
#include<cstdio>
#include<algorithm>

using namespace std;

struct edge
{
	int ed;
	edge* next;
}*st[500001],rd[1000000];

struct node
{
	int dep;
	int ft[20];
}ad[500001];

int n,m;
int cnt = 0,x,y,z,ct;
int ans1,ans2,ans3,ans,el;

void add_edge()
{
	int i,j;
	scanf("%d%d",&i,&j);
	rd[++cnt].next = st[i];
	rd[cnt].ed = j;
	st[i] = rd + cnt;
	rd[++cnt].next = st[j];
	rd[cnt].ed = i;
	st[j] = rd + cnt;
}

void make_tree(int now,int ls)
{
	ad[now].dep = ad[ls].dep + 1;
	ad[now].ft[0] = ls;
	for (int gen = 1; ad[ad[now].ft[gen-1]].ft[gen-1]; ++gen)
		ad[now].ft[gen] = ad[ad[now].ft[gen-1]].ft[gen-1];
	for (edge *pt = st[now]; pt; pt = pt->next)
		if (pt->ed != ls) make_tree(pt->ed,now);
}

int query(int p1,int p2)
{
	if (ad[p1].dep < ad[p2].dep) swap(p1,p2);
	if (ad[p1].dep > ad[p2].dep)
		for (int del = ad[p1].dep - ad[p2].dep, tmp = 0; del; del >>= 1, ++tmp)
			if (del & 1) 
				p1 = ad[p1].ft[tmp];
	if (p1 == p2) return p1;
	int i;
	for (i = 19; i > 0; --i)
		if (ad[p1].ft[i] != ad[p2].ft[i]) break;
	return query(ad[p1].ft[i],ad[p2].ft[i]);
}

void deal(int a, int b, int c)
{
	if (a == b) ans = c, el = a;
	if (a == c) ans = b, el = c;
	if (b == c) ans = a, el = b;
}

int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1; i < n; ++i)
		add_edge();
	make_tree(1,0);
	/*for (int i = 1; i <= n; ++i)
	  {
	  for (int j = 0; j <= 19; ++j)
	  printf("%d ",ad[i].ft[j]);
	  printf("\n");
	  }*/
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d%d",&x,&y,&z);
		ans1 = query(x,y);
		ans2 = query(y,z);
		ans3 = query(x,z);
		deal(ans1,ans2,ans3);
		ct = ad[x].dep + ad[y].dep + ad[z].dep - ad[el].dep*3;
		ct -= ad[ans].dep - ad[el].dep;
		printf("%d %d\n",ans,ct);
	}
	return 0;
}
