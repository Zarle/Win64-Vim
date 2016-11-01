#include<cstdlib>
#include<cstdio>

using namespace std;

int n,ans;


void hanoi(int ret,char st,char ed,char temp)
{// 将ret个柱子从st挪到ed柱，可以用temp做辅助
	//st is for start
	//ed is for end
	//temp is the middle
	if (ret == 0) return;
	hanoi(ret-1,st,temp,ed); // 把上面ret-1个盘子从st柱移到temp柱，可以用ed柱辅助
	cout << ret << ": " << st << " -> " << ed; // 将最下面的盘子从st柱移到ed柱
	// printf("%d: %c -> %c\n",ret,st,ed);
	hanoi(ret-1,temp,ed,st); // 将挪到temp的ret-1个盘子挪到ed柱上，可以用st柱辅助
	++ans;
}
int main()
{
	scanf("%d",&n);
	ans = 0;
	hanoi(n,'A','C','B');
	cout << ans << endl;
	//printf("%d\n",ans);
	return 0;
}
