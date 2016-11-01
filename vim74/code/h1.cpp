#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <set> 
using namespace std;
int a[100];
int b[100];
int c[100];
int main()
{
	//freopen("input","r",stdin);
	//freopen("output","w",stdout);
	int ind=0;
	for (int i=3;i<1000000;i++)
	{
		double ans=sqrt(i*i+(i+1)*(i+1));
		if (abs(ans-(int)(ans+0.5))<1e-5)
		{
			a[ind]=i;
			b[ind]=i+1;
			c[ind]=(int)(ans+0.5);
			ind++;
		}
	}
	//cout<<ind<<endl;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		printf("%d %d %d\n",a[n-1],b[n-1],c[n-1]);
	}
	return 0;
}
