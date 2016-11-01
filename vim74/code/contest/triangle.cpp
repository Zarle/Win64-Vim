#include <iostream>
#include <cmath>
using namespace std;
const int MAX=20;
long long ans[MAX][3];
int main()
{   int num=1;
    for (long long i=1; num<MAX; ++i){
        long long cur1=2*i*i+1, cur2=2*i*i-1;
        long long  k1=sqrt(cur1), k2=sqrt(cur2);
        if (k1*k1==cur1){ long long  n=i+k1;
            ans[num][0]=2*n*i; ans[num][1]=n*n-i*i; ans[num][2]=n*n+i*i; ++num;
        }
        if (k2*k2==cur2){ long long  n=i+k2;
            ans[num][0]=n*n-i*i; ans[num][1]=2*n*i; ans[num][2]=n*n+i*i; ++num;
        }
    }
    cin>>num;
    for (int i=0; i<num; ++i){ int cur;
        cin>>cur; cout <<ans[cur][0]<<" "<<ans[cur][1]<<" "<<ans[cur][2]<<endl;
    }
    return 0;
}

