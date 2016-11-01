#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=100000;
struct JS{int t,v,d,end;}a[N],b[N];

int i,j,n,m,n1,m1,x,y,z;
int X,TA,TB;
int cmp(const JS &x,const JS &y){return x.t<y.t;}
void init()
{
	n=m=0;
	scanf("%d",&X);
	scanf("%d%d",&n1,&m1);
	for (i=1;i<=n1;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		x+=y;
		if (x>=X&&x<=X+TB)
		{
			x+=y;
			a[++n].t=x;a[n].v=y;a[n].d=z;
		}
	}	
	for (i=1;i<=m1;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		x+=y;
		a[++n].t=x;a[n].v=y;a[n].d=z;		
	}
}
void work()
{
	int i,j,L,R,cur;
	//X+=TB;
	for (i=1;i<=n;i++)
	{
		if (X+TB<a[i].t+a[i].v||a[i].t+a[i].v<X) a[i].end=a[i].t;
		else
		{
			j=(X+TB-a[i].t)/a[i].v;
			if (j%2) j++;
			a[i].end=a[i].t+j*a[i].v;
		}
		if (a[i].end-a[i].t>TA) continue;
		b[++m].t=a[i].t;b[m].d=i;b[m].v=0;
		b[++m].t=a[i].end;b[m].d=i;b[m].v=1;
	}
	//for (i=1;i<=n;i++) printf("%d %d %d %d\n",a[i].t,a[i].end,a[i].d,a[i].v);
	//return;
	sort(b+1,b+m+1,cmp);
	//for (i=1;i<=m;i++) printf("%d %d %d\n",b[i].t,b[i].d,b[i].v);
	//return;
	long long sum=0,ans=0;
	for (i=1;i<=n;i++) sum=sum+a[i].d;
	L=1;R=0;
	for (i=1;i<=m;i++)
	{
		if (b[i].t-b[1].t>TA) break;
		R++;
		if (b[R].v==1) sum-=a[b[R].d].d;
	}
	ans=sum;
	for (R=R+1;R<=m;R=j+1)
	{
		j=R;while (j!=m&&b[j+1].t==b[j].t) j++;
		for (i=R;i<=j;i++)
			if (b[i].v==1) sum-=a[b[i].d].d;
		while (b[R].t-b[L].t>TA)
		{
			if (b[L].v==0) sum+=a[b[L].d].d;
			L++;
		}
		if (sum<ans) ans=sum;
	}
	printf("%lld\n",ans);
}
int main()
{
	freopen("9.in","r",stdin);
	freopen("9.out","w",stdout);
	
	while (scanf("%d%d",&TA,&TB)!=EOF)
	{
		init();
		work();
	}
	return 0;
}
