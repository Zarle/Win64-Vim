//f[i][j]��ʾ�ϲ���i��j�ѵĵõ������İ���ֵ
//��̬ת�Ʒ���f[i][j] = max(f[i][k]+f[k+1][j]+sum[i][j])
//i<= k < j, sum[i][j]Ϊ��i��j�ѵ�õ�廨�����ĺ�
//ʱ�临�Ӷ�O(n^3)

#include<cstdio>

#define max(a,b) a>b ? a:b

using namespace std;

int n,v;
int f[110][110];
int ss[110],sum[110][110];

int main()
{
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&v);
		ss[i] = ss[i-1]+v;
	}
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j)
			sum[i][j] = ss[j] - ss[i-1];
	for (int w = 1; w < n; ++w)
		for (int i  = 1; i <= n-w; ++i)
			for (int k = i; k < i+w; ++k)
				f[i][i+w] = max(f[i][i+w],f[i][k]+f[k+1][i+w]+sum[i][i+w]);
	printf("%d\n",f[1][n]);
	return 0;
}
