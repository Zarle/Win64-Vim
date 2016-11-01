#include<cstdio>
#include<cstring>

using namespace std;

double p[1000000];
char s[1000000];

long long q,l;

void get()
{
	q=0; 
	for (int i=0;i<l;i++)
		q=q*10+(s[i]-48);
}

int main()
{
	double ans = 0;
	for (int i = 1; i <= 245891; ++i)
	{
		double tmp = 1/(double)i;
		tmp /= i;
		ans +=(double) tmp;
		p[i] = ans;
	}
	while (gets(s))
	{
		l=strlen(s);
		if (l > 6) {printf("1.64493\n"); continue;}
		get();
		if (q <= 245891) printf("%.5lf\n",p[q]);
		else printf("%.5lf\n",p[245891]);
	}
	return 0;
}
