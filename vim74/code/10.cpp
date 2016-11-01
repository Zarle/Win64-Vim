#include<cstdio>
#include<cstring>
#include<algorithm>

#define lowbit(x) x & (-x)

using namespace std;

bool f[100010];
long long v[100010];
long long t[100010];
long long inst[100010];
long long cnt,T,root,size;
long long n,k,ans;

struct edge
{
	long long  ed;
	edge* next;
}e[100010],*head[100010];


void add_edge(long long st,long long ed)
{
	e[++cnt].ed = ed;
	e[cnt].next = head[st];
	head[st] = e + cnt;
}

void add(long long pos , long long num)   
{   
    while(pos <= size)   
    {   
          t[pos] += num;   
          pos += lowbit(pos);   
    }   
}

long long sum(long long end)   
{   
    long long tmp = 0;   
    while(end > 0)   
    {   
        tmp += t[end];   
        end -= lowbit(end);   
    }   
    return tmp;   
}  

void init()
{
	scanf("%lld%lld",&n,&k);
	cnt = 0;
	ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		head[i] = NULL;
		f[i] = false;
		scanf("%lld",&v[i]);
		inst[i] = v[i];
	}
	sort(inst + 1, inst + n +1);
	size = unique(inst + 1, inst + n + 1) - inst - 1;
	for (int i = 1; i <= n; i++)
		v[i] = lower_bound(inst+1,inst + size +1, v[i]) - inst;
	for (int i = 1; i < n; ++i)
	{
		long long a,b;
		scanf("%lld%lld",&a,&b);
		f[b] = true;;
		add_edge(a,b);
	}
	for (int i = 1; i <= n; ++i)
		if (!f[i]) root = i;
}

void dfs(long long now)
{
	long long ot = k / inst[v[now]];
	long long tmp = lower_bound(inst+1,inst + size +1, ot) - inst;
	if (ot < inst[tmp] || tmp > size) tmp--;
	ans +=  sum(tmp);
	add(v[now],1);
	for (edge * pt = head[now]; pt != NULL; pt = pt->next)
		dfs(pt->ed);
	add(v[now],-1);
}

int main()
{
	scanf("%lld",&T);
	while (T--)
	{
		init();
		dfs(root);
		printf("%lld\n",ans);
	}
	return 0;
}
