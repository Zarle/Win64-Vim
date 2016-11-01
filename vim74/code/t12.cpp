#include<cstdlib>
#include<iostream>

using namespace std;

struct node
{
	int num;
	node* next;
}head;

int i = 0;
node *pt = &head;
int cnt = 0;

int main()
{
	while (i != 99999)
	{
		++cnt;
		cin >> i;
		pt->num = i;
		pt->next = new node;
		pt = pt->next;
	}
	int f[cnt];
	pt = &head;
	cnt = 0;
	while (pt->num != 99999)
	{
		f[cnt++] = pt->num;
		pt = pt->next;
	}
	for (int i = 0; i < cnt; ++i)
		cout << f[i] << endl;
	return 0;
}
