#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int b[20];

void swap(int *x, int *y)
{
	int hold = *x;
	*x = *y;
	*y = hold;
}



int partition(int *c,int start, int end)
{
	int key = c[start], q = start, w = end;
	while (q < w)
	{
		while(q < w && c[w] >= key) --w;
        c[q] = c[w];
        while(q < w && c[q] <= key) ++q;
        c[w] = c[q];    
	}
	c[q] = key;
	return q;




}

void quickSort(int *a, int start, int end)
{
	if (start>=end) return;
	int pass = partition(a, start, end);
	if (start<end)
	{
		quickSort(a, pass + 1, end);

		quickSort(a, start, pass - 1);
	}
}


int main()
{
	srand(time(0));
	int b[20] = { 0 };
	for (int i = 0; i<20; i++)
	{
		b[i] = 1 + rand() % 100;
	}
	for (int j = 0; j<20; j++)
	{
		cout << b[j] << "\t";
	}
	quickSort(b,0,19);
	cout << "\n\n\n";
	for (int h = 0; h<20; h++)
	{
		cout << b[h] << "\t";
	}
	system("pause");
	return 0;
}
