#include<iostream>
#include<string>
#include<cstring>

using namespace std;

bool test;
char s[10000] = {};



int testPalindromes(char *s, int a, int b)
{
	if (s[a] != s[b])
		return 0;
	else if (a>b - 2)
		return 1;
	else
		testPalindromes(s, a + 1, b - 1);
}
int main()
{
    int count=0;
	char i=0;
	
	cout << "�����ַ���(�Իس�����)��";
	cin >> i;
	for (count ;i !='.';count++)
	{
		s[count] = i;
		cin >> i;
	}

	//cin >> s;
//	count = strlen(s);
	int m = testPalindromes(s,0,count-1);
	
	if (m==1)
		cout << "���ǻ����ַ�����"<<endl;
	else
		cout << "�ⲻ�ǻ����ַ�����"<<endl;

	//system("pause");
	return 0;
}
