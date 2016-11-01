#include<cstdio>
#include<cstdlib>

using namespace std;

int n,m;
int cnt;

struct node
{
	int l,r,data;
	int add,cnt;
}t[400010],*root;

void make_tree(node* now, int l, int r)
{
	if (l == r)
}

void init()
{
	scanf("%d%d",&n,&m);
	root = t+1;
	cnt = 1;
	for (int i = 1; i <= n; ++i)
		scanf("%lld",&num[i]);
	make_tree(root,l,r);
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		init();
		for (int i = 1; i <= m; ++i)
		{
			scanf("%d%d%d",&op,&l,&r);
			if (op == 3) printf("%lld\n",query(root,l,r));
			if (op == 2);
			if (op == 1);
		}
	}
	return 0;
}
