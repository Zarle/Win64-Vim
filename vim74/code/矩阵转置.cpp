#include<cstdio>

using namespace std;

int num;
int cnt,m,n;

struct node
{
	int col,value;
}row[1000],t_row[1000];
int rowSize[1000],t_rowSize[1000];
node *rowStart[1000],*t_rowStart[1000];

int main()
{
	printf("Please Input the Size of the Matrix (m*n):\n");
	scanf("%d%d",&m,&n);
	printf("Please Input the Matrix:\n");
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
		{
			scanf("%d",&num);
			if (num)
			{
				row[++cnt].value = num;
				row[cnt].col = j;
				++rowSize[i];
			}
		}
	printf("\n");

	rowStart[0] = row + 1;
	for (int i = 1; i <= m+1; ++i)
		rowStart[i] = rowStart[i-1] + rowSize[i-1];
	printf("row col value\n");
	for (int i = 1; i <= m; ++i)
		for (node *j = rowStart[i]; j < rowStart[i+1]; ++j)
		{
			printf("%3d %3d %3d\n", i, j->col, j->value);
			++t_rowSize[j->col];
		}

	t_rowStart[0] = t_row + 1;
	for (int i = 1; i <= n+1; ++i)
		t_rowStart[i] = t_rowStart[i-1] + t_rowSize[i-1];

	for (int i = 1; i <= m; ++i)
		for (node *j = rowStart[i]; j < rowStart[i+1]; ++j)
		{
			t_rowStart[j->col]->value = j->value;
			t_rowStart[j->col]->col = i;
			++t_rowStart[j->col];
		}

	printf("\nThe Transition:\n");
	t_rowStart[0] = t_row + 1;
	for (int i = 1; i <= n+1; ++i)
		t_rowStart[i] = t_rowStart[i-1] + t_rowSize[i-1];
	printf("row col value\n");
	for (int i = 1; i <= n; ++i)
		for (node *j = t_rowStart[i]; j < t_rowStart[i+1]; ++j)
			printf("%3d %3d %3d\n", i,j->col, j->value);
	return 0;
}
