//f[i]�������i��ķ�����
//��̬ת�Ʒ��� f[i] = f[i-1]+f[i-2]
//���Ӷ�O(n)

#include<cstdio>

using namespace std;

int n,f[46];

int main()
{
	scanf("%d",&n);
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i <= n; ++i)
		f[i] = f[i-1]+f[i-2];
	printf("%d\n",f[n]);
	return 0;
}
