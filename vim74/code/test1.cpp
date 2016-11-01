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
	
	cout << "输入字符串(以回车结束)：";
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
		cout << "这是回文字符串。"<<endl;
	else
		cout << "这不是回文字符串。"<<endl;

	//system("pause");
	return 0;
}
