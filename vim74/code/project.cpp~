#include<cstdio>
#include<cstdlib>
#include<cstring>

#define check1(i) i & 1
#define check2(i) (i >> 1) & 1
#define check3(i) (i >> 2) & 1

using namespace std;


const int f1 = 1, f2 =2, f3 = 4;
int tar[8];
int step[30];
int tmp = 0;
bool use[8];
bool f[16777216];
bool ff[16777216];
int line[40321];
int op,clo,ed;
int hsh[40320];

bool judge(int k)
{
	int temp = 0;
	for (int i = 0; i < 8; ++i)
		temp = (temp << 3) + tar[i];
	if (f[temp])
	{
		printf("%d: %d + %d\n",hsh[line[clo]],temp,k);
		ff[hsh[line[clo]]] = true;
		clo = (clo % 40320) + 1;
		return true;
	}
	return false;
}

void Tof_1_a()
{
	for (int i = 0; i < 8; ++i)
		tar[i] ^= f1;
}

void Tof_1_b()
{
	for (int i = 0; i < 8; ++i)
		tar[i] ^= f2;
}

void Tof_1_c()
{
	for (int i = 0; i < 8; ++i)
		tar[i] ^= f3;
}

void Tof_b_a()
{
	for (int i = 0; i < 8; ++i)
		if (check2(tar[i])) tar[i] ^= f1;
}

void Tof_c_a()
{
	for (int i = 0; i < 8; ++i)
		if (check3(tar[i])) tar[i] ^= f1;
}

void Tof_a_b()
{
	for (int i = 0; i < 8; ++i)
		if (check1(tar[i])) tar[i] ^= f2;
}

void Tof_c_b()
{
	for (int i = 0 ; i < 8; ++i)
		if (check3(tar[i])) tar[i] ^= f2;
}

void Tof_a_c()
{
	for (int i = 0; i < 8; ++i)
		if (check1(tar[i])) tar[i] ^= f3;
}

void Tof_b_c()
{
	for (int i = 0; i < 8; ++i)
		if (check2(tar[i])) tar[i] ^= f3;
}

void Tof_cb_a()
{
	for (int i = 0; i < 8; ++i)
		if (check2(tar[i]) & check3(tar[i])) tar[i] ^= f1;
}

void Tof_ca_b()
{
	for (int i = 0; i < 8; ++i)
		if (check3(tar[i]) & check1(tar[i])) tar[i] ^= f2;
}

void Tof_ba_c()
{
	for (int i = 0; i < 8; ++i)
		if (check2(tar[i]) & check1(tar[i])) tar[i] ^= f3;
}

void search()
{
	Tof_1_a(); if (judge(1)) return; else Tof_1_a();
	Tof_1_b(); if (judge(2)) return; else Tof_1_b();
	Tof_1_c(); if (judge(3)) return; else Tof_1_c();
	Tof_b_a(); if (judge(4)) return; else Tof_b_a();
	Tof_c_a(); if (judge(5)) return; else Tof_c_a();
	Tof_a_b(); if (judge(6)) return; else Tof_a_b();
	Tof_c_b(); if (judge(7)) return; else Tof_c_b();
	Tof_a_c(); if (judge(8)) return; else Tof_a_c();
	Tof_b_c(); if (judge(9)) return; else Tof_b_c();
	Tof_cb_a(); if (judge(10)) return; else Tof_cb_a();
	Tof_ca_b(); if (judge(11)) return; else Tof_ca_b();
	Tof_ba_c(); if (judge(12)) return; else Tof_ba_c();
	op = (op % 40320) + 1;
	line[op] = line[clo];
	clo = (clo % 40320) + 1;
}

void split(int k)
{
	int temp = hsh[k];
	for (int i = 7; i >= 0; --i)
	{
		tar[i] = temp % 8;
		temp /= 8;
	}
}

void initialize(int dep,int num)
{
	if (dep == 9)
	{
		hsh[tmp++] = num;
		f[num] = false;
	}
	for (int i = 0; i < 8; ++i)
		if (!use[i])
		{
			use[i] = true;
			initialize(dep+1,(num<<3)+i);
			use[i] = false;
		}
}

int main()
{
	freopen("ans","w",stdout);
	memset(use,0,sizeof(use));
	memset(f,0,sizeof(f));
	memset(ff,0,sizeof(ff));
	initialize(1,0);
	f[hsh[0]] = true;
	for (int i = 1; i < 40320; ++i)
		line[i] = i;
	/*for (int i = 0; i < 40320; ++i)
	{
		printf("%d: ",hsh[i]);
		split(i);
		for (int j = 0; j < 8; ++j)
			printf("%d ",tar[j]);
		printf("\n");
	}*/
	clo = 1;
	ed = op = 40320-1;
	while (clo != op + 1)
	{
		if (clo == (ed % 40320) + 1)
		{
			ed = op;
			memcpy(f,ff,sizeof(f));
		}
		split(line[clo]);
		search();
	}
	return 0;
}
