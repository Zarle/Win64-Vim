#include<cstdlib>
#include<cstdio>

#define lowbit(x) (x&(-x))
#define max(a,b) (a>b? a : b)


using namespace std;

int c[10000], num[10000], n; 
int ans = 0;
int mx = 0;

int sum(int x)   //求区间和
{
	if (x == 0) return 0;
    return c[x] + sum(x - lowbit(x));
}

void add(int x, int val) //开始构建一个树状数组， 也可以修改数组
{
    while(x <= mx)
    {
        c[x] += val;
        x += lowbit(x);
    }
} 

int main()
{
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&num[i]);
		mx = max(num[i],mx);
	}
	for (int i = 1; i <= n; ++i)
	{
		ans += sum(num[i]-1);
		add(num[i],1);
	}
	printf("%d",ans);
	return 0;
}
