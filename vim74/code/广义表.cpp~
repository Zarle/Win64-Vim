#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;


struct node
{
	int utype;
	node *tlink;
	struct data
	{
		node *hlink;
		char value;
		int ref;
	}info;
}*root[30];

string s[30];
int l[30];
int t1,t2,n;

void new_list()
{
	for (int i = 1; i <= n; ++i)
		l[i] = s[i].length();
	
	for (int k = 1; k <= n; ++k)
	{
		root[k] = new node;
		root[k]->utype = 0;
		root[k]->info.ref = 1;
		root[k]->tlink = new node;
		node* pt = root[k]->tlink;
		for (int i = 0; i < l[k]-1; ++i)
		{
			pt->utype = 1;
			pt->info.value = s[k][i];
			pt->tlink = new node;
			pt = pt->tlink;
		}
		pt->utype = 1;
		pt->info.value = s[k][l[k]-1];
		pt->tlink = NULL;
	}
}

void merge(int s1,int s2,int ll)
{
	node* pt1 = root[s1];
	node* pt2 = root[s2];
	int cnt1 = 0,cnt2 = 0;

	while (cnt1 != l[s1]-ll)
	{
		if (pt1->utype <= 1)
		{
			pt1 = pt1->tlink;
			if (pt1->utype == 1) ++cnt1;
		}
		if (pt1->utype == 2) pt1 = pt1->info.hlink;
	}

	while (cnt2 != l[s2]-ll)
	{
		if (pt2->utype <= 1)
		{
			pt2 = pt2->tlink;
			if (pt2->utype == 1) ++cnt2;
		}
		if (pt2->utype == 2) pt2 = pt2->info.hlink;
	}

	node *pt = pt2->tlink,*tmp;
	while (pt!=NULL)
	{
		if (pt->utype == 2)
			tmp = pt->info.hlink;
		else tmp = pt->tlink;
		delete[] pt;
		pt = tmp;
	}

	if (pt1->utype == 0)
	{
		pt2->tlink = new node;
		pt2 = pt2->tlink;
		pt2->utype = 2;
		pt2->info.hlink = pt1;
	}
	else
	{
		pt1 = pt1->tlink;
		if (pt1->utype == 2)
		{
			pt2->tlink = pt1;
			pt1->info.hlink->info.ref++;
		}
		if (pt1->utype == 1)
		{
			node *tmp = new node;
			tmp->utype = 2;
			tmp->info.hlink = new node;
			tmp->info.hlink->utype = 0;
			tmp->info.hlink->info->ref = 2;
			tmp->info.hlink->tlink = pt1->tlink;
			pt1->tlink = tmp;
			pt2->tlink = tmp;
		}
	}

}

void make_list()
{
	new_list();
	for (int i = 2; i <= n; ++i)
	{
		int flag = 0, num = 0;
		for (int j = 1; j < i; ++j)
		{
			int len = 0;
			while (s[i][l[i]-len-1] == s[j][l[j]-len-1]) 
				if (len < l[i] && len < l[j]) ++len;
				else break;
			if (len > num)
			{
				flag = j;
				num = len;
			}
		}
		if (flag) merge(flag,i,num);
	}

	/*puts("");
	for (int i = 1; i <= n; ++i)
	{
		for (node* pt = root[i].next; pt; pt = pt->next)
			printf("%c",pt->data);
		printf("\n");
	}
	puts("");*/
}

node* query(int t1, int t2)
{
	node *pt1, *pt2 = root[t2]->tlink;
	while (pt2 != NULL)
	{
		pt1 = root[t1]->tlink;
		while (pt1 != NULL && pt1 != pt2)
		{
			if (pt1->utype != 2)
				pt1 = pt1->tlink;
			else pt1 = pt1->info.hlink;
			if (pt1 != pt2)
			{
				if (pt2->utype != 2)
					pt2 = pt2->tlink;
				else pt2 = pt2->info.hlink;
			}
			else return pt1;
		}
	}
	return NULL;
}

int main()
{
	printf("Please Input the Number of Strings: ");
	scanf("%d",&n);
	printf("Please Input Strings:\n");
	for (int i = 1; i <= n; ++i)
		cin >> s[i];

	make_list();

	printf("Please Input the Number of Questions:\n");
	int T;
	scanf("%d",&T);
	while (T--)
	{
		printf("Please Input the Numeber of two Strings to Query:\n");
		scanf("%d %d",&t1,&t2);
		node* pt = query(t1,t2);
		if (pt == NULL) printf("No Same Suffix\n");
		else
		{
			printf("%x\n",pt);
			for (;pt!=NULL; pt = pt->utype == 2 ? pt->info.hlink:pt->tlink)
				if (pt->utype == 1) printf("%c",pt->info.value);
			printf("\n");
		}
	}
	return 0;
}
