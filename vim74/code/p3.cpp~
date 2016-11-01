#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

int n,n1[1000],n2[1000];
int ans1,ans2;

int search(int tar)
{
	int l = 1, r = n, mid, ot;
	while (l != r)
	{
		mid = (l+r)>>1;
		ot = tar - mid;
		if (n1[mid] >= n2[ot] && n1[mid] <= n2[ot+1]) return mid;
		if (n1[mid] > n2[ot] && n1[mid] > n2[ot+1])
		{
			r = mid;
			continue;
		}
		if (n1[mid] < n2[ot])
		{
			l = mid+1;
			continue;
		}
	}
	mid = (l+r)>>1;
	ot = tar - mid;
	if (n1[mid] >= n2[ot] && n1[mid] <= n2[ot+1]) return mid;
	return 0;
}

int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
		scanf("%d",&n1[i]);
	for (int i = 1; i <= n; ++i)
		scanf("%d",&n2[i]);
	n1[n+1] = 1000000;
	n2[n+1] = 1000000;
	ans1 = search(n);
	if (!ans1)
	{
		for (int i = 1; i <= n; ++i)
			swap(n1[i],n2[i]);
		ans1 = search(n);
	}
	ans1 = n1[ans1];
	ans2 = search(n+1);
	if (!ans2)
	{
		for (int i = 1; i <= n; ++i)
			swap(n1[i],n2[i]);
		ans2 = search(n+1);
	}
	ans2 = n1[ans2];
	printf("%.1lf",((double)(ans1+ans2))/2);
	return 0;
}
