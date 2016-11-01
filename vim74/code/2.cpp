#include<cstdio>

using namespace std;

int main()
{
	double ans = 0;
	for (int i = 1; i <= 100; ++i)
	{
		ans += 1/(double)(i*i);
		printf("%.5lf\n",ans);
	}
	return 0;
}
