#include<cstdlib>
#include<cstdio>
#include<cmath>

#define max(a,b) (a > b ? a : b)

using namespace std;

char st[100100];
int len = 0;
int MinimumRepresentation(char *s, int l)    
{    
	int i,j,k;  
	i=0;j=1;k=0;  
	while(i<l&&j<l)  
	{  
		k=0;  
		while(s[i+k]==s[j+k]&&k<l) k++;  
		if(k==l) return i;  
		if(s[i+k]>s[j+k])   
			if(i+k+1>j) i=i+k+1;  
			else i=j+1;  
		else if(j+k+1>i) j=j+k+1;  
		else  j=i+1;   
	}  
	if(i<l) return i;  
	else return j;  
}   


int main()
{
	scanf("%s",st);
	while (st[len]) ++len;
	printf("%d\n",len);
	/*scanf("%d",&len);
	  while (true)
	  {
	  char tmp = getchar();
	  if (tmp == EOF) break;
	  if (tmp == '\n') continue;
	  s[++cnt] = tmp;
	  }*/
	printf("%d",MinimumRepresentation(st,len));
	return 0;
}

