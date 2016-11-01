#include<cstdio>
#include<cstdlib>

using namespace std;

int T;

int solve()  
{  
	int i, n, top, temp, cnt = 0;  
	int arr[100050];
	scanf("%d",&n);
	top = 0;  
	arr[0] = -1;  
	for (i = 0; i < n; i++)  
	{  
		scanf("%d",&temp);  
		if (temp > arr[top])  
		{  
			arr[++top] = temp;
			continue;
		}  
		if (temp == 0)
		{
			++cnt;
			arr[1] = 0-cnt;
			continue;

		}
		int low = 1, high = top;  
		int mid;  
		while(low <= high)  
		{  
			mid = (low + high) / 2;  
			if (temp > arr[mid]+cnt)  
			{  
				low = mid + 1;  
			}  
			else  
			{  
				high = mid - 1;  
			}  
		}  
		temp -= cnt;
		arr[low] = temp;  
	}  
	return top+cnt;
}  

int main()
{
	scanf("%d",&T);
	for (int i = 1; i <= T; ++i)
		printf("Case #%d: %d\n",i,solve());
	return 0;
}
