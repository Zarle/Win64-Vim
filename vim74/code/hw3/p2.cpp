//f[i]��ʾ������i����Ƽʱ����С��Ծ����
//��̬ת�Ʒ���f[i] = min(f[j]+1) (j < i ���ܴӵ�j����Ƽ��������i����Ƽ��
//���Ӷ�O(n^2)
//
//Ҳ����˳�ƣ�f[j] = min(f[j],f[i]+1) (jΪ�ܴӵ�i����Ƽ������λ��)
//���Ӷ�O(sum(x[i])) (i = 1..n)

#include<cstdio>
#define min(a,b) a<b ? a:b

using namespace std;

int n,s[10010];
int f[10010];

int main()
{
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&s[i]);
		f[i] = 0x3f3f3f3f;
	}
	f[1] = 1;
	for (int i = 2; i <= n; ++i)
		for (int j = 1; j < i; ++j)
			if (j+s[j] >= i) f[i] = min(f[i],f[j]+1);
	printf("%d\n",f[n]+1);
	return 0;
}
