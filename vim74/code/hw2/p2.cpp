//因为半径和圆心的y值确定
//所以当一个点在圆上时，能够确定圆心位置
//能够证明一个点在圆上时，比在圆内时覆盖的点更多
//将坐标以x轴为关键字排序，每次确定圆心
//当一个点不能够被上一个圆覆盖时，一定在下一个圆的边界上
//时间复杂度O(NlogN)，可能会有精度问题

#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>

using namespace std;

struct node
{
	int x,y;
} p[10010];
int d,n;
int ans;
const double eps = 1e-5;

bool cmp(node x, node y)
{
	return x.x < y.x;
}

int main()
{
	scanf("%d%d",&d,&n);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d",&p[i].x,&p[i].y);
	sort(p+1,p+n+1,cmp);
	double pt = p[1].x + sqrt(d*d-p[1].y*p[1].y);
	ans = 1;
	for (int i = 2; i <= n; ++i)
	{
		double delta = p[i].x - pt;
		double dist = sqrt(p[i].y*p[i].y+delta*delta);
		if (dist < d) continue;
		if (abs(dist-d)<eps) continue;
		pt = p[i].x + sqrt(d*d-p[i].y*p[i].y);
		++ans;
	}
	printf("%d\n",ans);
	return 0;
}
