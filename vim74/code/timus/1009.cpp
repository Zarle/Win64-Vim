#include<cstdio>

using namespace std;

long long f[100000][2];
long long n,k;

int main()
{
	scanf("%lld%lld",&n,&k);
	f[1][1] = k-1;
	for (int i = 2; i <= n; ++i)
	{
		f[i][0] = f[i-1][1];
		if (i != 2) f[i][1] = (f[i-1][1]+f[i-1][0])*(k-1);
		else f[i][1] = f[i-1][1]*(k-1);
	}
	printf("%lld\n",f[n][0]+f[n][1]);
	return 0;
}
