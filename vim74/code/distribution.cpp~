#include<cstdlib>
#include<cstdio>
#include<bitset>

using namespace std;

char name[100][100];
int cnt,to,ct;
int match[100];
int ans[100];
bitset<100> used;
bool f;

struct edge
{
	int ed;
	edge *next;
}con[10000],*st[100];

void add_edge(int fr,int to)
{
	con[++ct].next = st[fr];
	st[fr] = &con[ct];
	con[ct].ed = to;
}

void init()
{
	while (scanf("%s",name[++cnt]) != EOF)
		while (scanf("%d",&to) == 1)
			add_edge(cnt,to);
}

bool crosspath(int now)
{
	for (edge *pt = st[now]; pt; pt = pt->next)
	{
		if (!used.test(pt->ed))
		{
			used.set(pt->ed);
			if (!match[pt->ed] || crosspath(match[pt->ed]))
			{
					match[pt->ed] = now;
					return true;
			}
		}
	}
	return false;
}

void hungary()
{
	for (int i = 1; i < cnt; ++i)
	{
		crosspath(i);
		used.reset();
	}
}

void count()
{
	for (int i = 0; i < 100; ++i)
		if (match[i]) ans[match[i]] = i;
}

void print()
{
	for (int i = 1; i < cnt; ++i)
		if (ans[i]) printf("%s %d\n",name[i],ans[i]);
		else f = true;
	printf("\n");
	if (f)
	{
		printf("These people don't have their ideal numbers£º\n");
		for (int i = 1; i < cnt; ++i)
			if (!ans[i]) printf("%s  ",name[i]);
	}
	printf("\n");
	for (int i = 1; i <= 23; ++i)
		printf("**");
	printf("\n");
	printf("Version: 1.0\n");
	printf("This program is written by Yulin Shen from SEU\n");
	for (int i = 1; i <= 23; ++i)
		printf("**");
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	init();
	hungary();
	count();
	print();
	return 0;
}
