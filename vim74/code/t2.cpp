#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

int num[1001][1001],map[1001][1001];
int n,px,py;
bool f = false;

struct node
{
	int v,dir;
}ans[1001][1001];

struct nod
{
	int v;
	char s[2000];
}fin[2];

void deal(int k)
{
	memset(map,0,sizeof(map));
	for (int i = 1; i <= n; ++i)
		for (int j =  1; j <= n; ++j)
		{
			int tmp = num[i][j];
			int cnt =  0;
			while (!(tmp % k))
			{
				tmp /= k;
				++cnt;
			}
			map[i][j] = cnt;
		}
}

void dp()
{
	ans[1][1].v = map[1][1];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			if (i > 1 && j > 1)
			{
				if (ans[i-1][j].v < ans[i][j-1].v)
				{
					ans[i][j].v = ans[i-1][j].v + map[i][j];
					ans[i][j].dir = 0;
				}
				else
				{
					ans[i][j].v = ans[i][j-1].v + map[i][j];
					ans[i][j].dir = 1;
				}
				continue;
			}
			if (i > 1)
			{
				ans[i][j].v = ans[i-1][j].v + map[i][j];
				ans[i][j].dir = 0;
				continue;
			}
			if (j > 1)
			{
				ans[i][j].v = ans[i][j-1].v + map[i][j];
				ans[i][j].dir = 1;
				continue;
			}
		}
}

void save(int k)
{
	fin[k].v = ans[n][n].v;
	int i = n, j = n;
	for (int z = 2*n - 1; z > 0; --z)
	{
		if (ans[i][j].dir)
		{
			fin[k].s[z] = 'R';
			j--;
		}
		else
		{
			fin[k].s[z] = 'D';
			i--;
		}
	}
}

void print()
{
	if (!f)
	{
		if (fin[0].v < fin[1].v)
		{
			printf("%d\n",fin[0].v);
			for (int i = 2; i <= 2*n-1; ++i)
				printf("%c",fin[0].s[i]);
			printf("\n");
		}
		else
		{
			printf("%d\n",fin[1].v);
			for (int i = 2; i <= 2*n-1; ++i)
				printf("%c",fin[1].s[i]);
			printf("\n");
		}
	}
	else
	{
		if (!fin[0].v)
		{
			printf("%d\n",fin[0].v);
			for (int i = 2; i <= 2*n-1; ++i)
				printf("%c",fin[0].s[i]);
			printf("\n");
			return;
		}
		if (!fin[1].v)
		{
			printf("%d\n",fin[1].v);
			for (int i = 2; i <= 2*n-1; ++i)
				printf("%c",fin[1].s[i]);
			printf("\n");
			return;
		}
		printf("1\n");
		for (int i = 1; i < px; ++i)
			printf("D");
		for (int j = 1; j < py; ++j)
			printf("R");
		for (int i = px; i < n; ++i)
			printf("D");
		for (int j = py; j < n; ++j)
			printf("R");
		printf("\n");
	}
}

int main()
{
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			scanf("%d",&num[i][j]);
			if (!num[i][j])
			{
				num[i][j] = 10;
				f = true;
				px = i, py = j;
			}
		}
	deal(2);
	dp();
	save(0);
	deal(5);
	dp();
	save(1);
	print();
	return 0;
}
