//因为每一个人都必须上船，且每船至多2人，所以先安排较重的人
//将体重排序,每次将最重的人和最轻的人安排在一起
//如果体重之和大于载重量，则较胖的人一人一船
//可证明贪心的正确性
//时间复杂度O(NlogN)

#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

int w[10010];
int n,m,h,t;
int ans;

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; ++i)
		scanf("%d",&w[i]);
	sort(w+1,w+n+1);
	if (w[n] > m)
	{
		printf("No Answer!\n");
		return 0;
	}
	h = 1;
	t = n;
	while (h <= t)
	{
		if (w[h] + w[t] <= m)
		{
			++h;
			--t;
		}
		else --t;
		++ans;
	}
	printf("%d\n",ans);
	return 0;
}
