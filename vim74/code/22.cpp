#include <stdio.h>
#include <cstring>
//#include <string>

using namespace std;

long long i,L;
double A[300001];
long long N;
char B[100001];
int main(){
	//freopen("1002.in","r",stdin);
	//freopen("1002.out","w",stdout);
	A[0]=(double)0.00;
	for (i=1;i<=300000;i++) A[i]=(double)A[i-1]+(double)1/(i*i);
	//printf("%.5lf\n",A[299999]);
	//gets(B);
	//while (scanf("%lld\n",&N)==1){
	while(gets(B)){
		  L=strlen(B);
		  if (L>6){
		  	 printf("1.64493\n");
		  	 continue;
		  }
		  N=0;
		  
		  for (i=0;i<L;i++){
		      N=N*10+(B[i]-48);
		      B[i]=0;
		  }		  //B.length();
		  if (N<300000) {
		     printf("%.5lf\n",A[N]);
	         continue;
		  }
		  printf("1.64493\n");      
		  //double Sum=A[30000000];
		  //for (i=30000000;i<=N;i++) Sum=(double)Sum+1/(i*i);
		  //printf("%.5lf\n",A[30000000]);
		  //printf("1.64493\n");
	}	
	return 0;
} 
