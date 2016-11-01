#include<cstdio>
#include<algorithm>

using namespace std;

struct tt
{
	long long st,ed,v;
}t[20010];

long long n,m,ta,tb,cnt,sum,x;
long long d[20010][3];
long long tmp1,tmp2;

bool cmp(tt a, tt b)
{
	if (a.st == b.st) return a.ed < b.ed;
	return a.st < b.st;
}

void get(long long st,long long c,long long v)
{
	if (st + 2*c < x || st+2*c > x+tb)
	{
		t[++cnt].st = max((long long)0,st+c-ta);
		t[cnt].ed = st+c;
		t[cnt].v = v;
		return;
	}
	tmp1 =  ((x+tb-st)/(2*c))*2*c+st+c-ta;
	tmp2 = st + c;
	if (tmp1 <= tmp2)
	{
		t[++cnt].st = tmp1;
		t[cnt].ed = tmp2;
		t[cnt].v = v;
	}
}

void deal()
{
	for (int i = 1; i <= n; ++i)
	{
		if (d[i][0]+d[i][1] < x || d[i][0]+d[i][1] > x + tb) sum -= d[i][2];
		else get(d[i][0]+d[i][1],d[i][1],d[i][2]);
	}
	for (long long i = n+1; i <= n+m; ++i)
		get(d[i][0],d[i][1],d[i][2]);
	sort(t+1,t+cnt+1,cmp);
	long long now = t[1].v;
	long long ans = t[1].v;
	long long top = 1;
	for (int i = 2; i <= cnt; ++i)
	{
		while (t[top].ed < t[i].st && top < i) 
			now -= t[top++].v;
		now += t[i].v;
		ans = max(ans,now);
	}
	if (cnt!=0) sum -= ans;
	printf("%lld\n",sum);
}

int main()
{
	//freopen("9.in","r",stdin);
	//freopen("9.ans","w",stdout);
	while(~scanf("%lld%lld",&ta,&tb))
	{
		cnt = 0;
		sum = 0;
		scanf("%lld",&x);
		scanf("%lld%lld",&n,&m);
		for (int i = 1; i <= n+m; ++i)
		{
			scanf("%lld%lld%lld",&d[i][0],&d[i][1],&d[i][2]);
			sum += d[i][2];
		}
		deal();
	}
	return 0;
}
