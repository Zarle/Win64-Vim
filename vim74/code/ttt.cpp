#include<iostream>

using namespace std;

int a[3][5];
int **p;

int main()
{
	p = a;
	cout << **(a+5);
	return 0;
}
