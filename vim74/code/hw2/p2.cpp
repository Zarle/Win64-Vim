//��Ϊ�뾶��Բ�ĵ�yֵȷ��
//���Ե�һ������Բ��ʱ���ܹ�ȷ��Բ��λ��
//�ܹ�֤��һ������Բ��ʱ������Բ��ʱ���ǵĵ����
//��������x��Ϊ�ؼ�������ÿ��ȷ��Բ��
//��һ���㲻�ܹ�����һ��Բ����ʱ��һ������һ��Բ�ı߽���
//ʱ�临�Ӷ�O(NlogN)�����ܻ��о�������

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