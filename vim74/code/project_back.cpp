#include<cstdio>
#include<cstdlib>

#define check1(i) i & 1
#define check2(i) (i >> 1) & 1
#define check3(i) (i >> 2) & 1

using namespace std;


const int f1 = 1, f2 =2, f3 = 4;
int tar[8];
int step[20];
int cnt = 0;

bool judge()
{
	for (int i = 1; i < 8; ++i)
		if (tar[i] != i) return false;
	return true;
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

bool search(int dep)
{
	if (judge()) 
	{
		cnt = dep-1;
		return true;
	}
	if (dep-1 == 3) return false;
	Tof_1_a(); step[dep] = 1; if (search(dep+1)) return true; Tof_1_a();
	Tof_1_b(); step[dep] = 2; if (search(dep+1)) return true; Tof_1_b();
	Tof_1_c(); step[dep] = 3; if (search(dep+1)) return true; Tof_1_c();
	Tof_b_a(); step[dep] = 4; if (search(dep+1)) return true; Tof_b_a();
	Tof_c_a(); step[dep] = 5; if (search(dep+1)) return true; Tof_c_a();
	Tof_a_b(); step[dep] = 6; if (search(dep+1)) return true; Tof_a_b();
	Tof_c_b(); step[dep] = 7; if (search(dep+1)) return true; Tof_c_b();
	Tof_a_c(); step[dep] = 8; if (search(dep+1)) return true; Tof_a_c();
	Tof_b_c(); step[dep] = 9; if (search(dep+1)) return true; Tof_b_c();
	Tof_cb_a(); step[dep] = 10; if (search(dep+1)) return true; Tof_cb_a();
	Tof_ca_b(); step[dep] = 11; if (search(dep+1)) return true; Tof_ca_b();
	Tof_ba_c(); step[dep] = 12; if (search(dep+1)) return true; Tof_ba_c();
	return false;
}

int main()
{
	freopen("ans","w",stdout);
	for (int i = 0; i < 8; ++i)
		scanf("%d",&tar[i]);
	cnt = 1;
	if (search(1))
		for (int i = 1; i <= cnt; ++i)
			printf("%d ",step[i]);
	return 0;
}
