#include<cstdio>
#include<cstdlib>
#include<bitset>

using namespace std;

int n,m,T,dist;
int pt[100010][2];
bool flag;
bitset<300010> f;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		f.reset();
		flag = false;
		for (int i = 1; i <= n; ++i)
			scanf("%d%d",&pt[i][0],&pt[i][1]);
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j < i; ++j)
			{
				dist = abs(pt[i][0]-pt[j][0])+abs(pt[i][1]-pt[j][1]);
				if (f.test(dist))
				{
					flag = true;
					break;
				}
				else f.set(dist);
			}
			if (flag)
			{
				printf("YES\n");
				break;
			}
		}
		if (!flag) printf("NO\n");
	}
	return 0;
}
