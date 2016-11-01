#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int n,c,l,r,x,i,T;
long long a[100010];

inline bool test(int k)
{
	long long ans=0,now=0;
	queue<long long>q;
	for (int j = 1; j <= 100; ++j)
	{
		q.push(j);
		q.pop();
		ans = 0;
	}
	i=0;
	for (;a[i]==0&&i<n;i++);
	if(i>0)i--;
	int tn=(n-i-1)%(k-1);
	if(tn)
	{
		tn++;
		while(tn--)
			now+=a[i++];
		ans+=now;
		q.push(now);
	}

	while(i<n||q.size()>1)
	{
		now=0;
		for(int j=0;j<k;j++)
		{
			if(i==n&&q.size() == 0)
				break;
			else
				if(i==n)
				{
					now+=q.front();
					q.pop();
					continue;
				}
				else
					if(q.size() == 0)
					{
						now+=a[i++];
						continue;
					}

			if(a[i]<q.front())
				now+=a[i++];
			else
			{
				now+=q.front();
				q.pop();
			}
		}
		ans+=now;
		q.push(now);
	}
	return (ans<=c) ? true : false;
}

void init()
{
	scanf("%d%d",&n,&c);
	for(int i=0;i<n;i++)
		scanf("%lld",a+i);
}


int main()
{
	scanf("%d",&T);
	for(;T;T--)
	{
		init();
		sort(a,a+n);
		l=2;r=n;
		while(l<r)
		{
			x=(l+r)/2;
			if(test(x)==true) r=x; else l=x+1;
		}
		printf("%d\n",l);
	}
}

