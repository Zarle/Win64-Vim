#include<cstdlib>
#include<cstdio>

using namespace std;

int tt[10000000];
char s[100] = "thecourseoftrueloveneverdidrunsmooth";
char s1[100] = "shenyulinsyl";
char key1[100] = "jjaoounzares";
char key[2][18];
int mat[2][6];
int mat1[2][18];
int m1[2][2] ={{0,5},{3,1}};
int m2[2][2] ={{1,4},{1,3}};

int main()
{
	for (int i = 0; i < 36; ++i)
	{
		int tmp = s[i] + key1[i % 12] - 'a';
		if (tmp  > 'z') tmp -= 26;
		s[i] = tmp;
	}
	for (int i = 0; i < 36; ++i)
		printf("%c",s[i]);
	printf("\n");
	for (int i = 0; i < 18; ++i)
		for (int j = 0; j < 2; ++j)
			mat1[j][i] = s[2*i+j] - 'a';
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 18; ++j)
			printf("%3d ",mat1[i][j]);
		printf("\n");
	}
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 18; ++j)
		{
			for (int k = 0; k < 2; ++k)
				key[i][j] += m2[i][k]*mat1[k][j];
			key[i][j] = key[i][j] % 26;
			printf("%d ",key[i][j]);
		}
	printf("\n");
	for (int i = 0; i < 18; ++i)
		for (int j = 0; j < 2; ++j)
			printf("%c",'a' + key[j][i]);
	printf("\n");
	return 0;
}
