#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>

using namespace std;

char st[110];

int main()
{
	while (~scanf("%s",st))
	{
		if (strlen(st) > 10)
		{
			printf("TAT\n");
			continue;
		}
		long long a;
		sscanf(st,"%lld",&a);
		if (a > 4294967295 || a == 0)
		{
			printf("TAT\n");
			continue;
		}
		int cnt = 0;
		while (a != 1)
		{
			a = (long long)sqrt(a);
			++cnt;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
