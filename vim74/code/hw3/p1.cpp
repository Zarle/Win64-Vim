//f[i]代表到达第i层的方案数
//动态转移方程 f[i] = f[i-1]+f[i-2]
//复杂度O(n)

#include<cstdio>

using namespace std;

int n,f[46];

int main()
{
	scanf("%d",&n);
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i <= n; ++i)
		f[i] = f[i-1]+f[i-2];
	printf("%d\n",f[n]);
	return 0;
}
