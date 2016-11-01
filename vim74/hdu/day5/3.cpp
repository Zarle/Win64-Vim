#include<cstdio>

using namespace std;

long long cnt,sum,n,num[1000010];

int main()
{
	while (~scanf("%lld",&n))
	{
		for (long long i = 1; i <= n; ++i)
			scanf("%lld",&num[i]);
		cnt = 0;
		sum = 0;
		for (long long i = n; i > 0; --i)
		{
			sum += num[i];
			if (sum >= 0)
			{
				++cnt;
				sum = 0;
			}
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
