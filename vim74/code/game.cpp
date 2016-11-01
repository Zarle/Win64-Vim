#include<cstdio>
using namespace std;

char s[100];
int ans;

int main()
{
	scanf("%s",s);
	for (int i = 0; s[i]; i++)
		ans = ans * 2 + (s[i] - '0');
	printf("%d\n",ans);
	return 0;
}
