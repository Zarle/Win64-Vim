#include <iostream>
#include <cstring>

using namespace std;

string target = "abcabbaba";//目标字符串
string s;
int *n;

int getNext(string pat)//用递归算法求next函数
{
	int k = -1;
	n[0] = -1;//递归的初始状态
	for(int j = 0;j < pat.length();j++)
	{
		if(k == -1 || pat[j] == pat[k])//如果当前前缀子串的下一个字符与后缀子串的下一个字符相同，则next（j+1）= next（j）+ 1
		{
			k++;
			n[j+1] = k;
		}
		else//如果当前前缀子串的下一个字符与后缀子串的下一个字符不同，则在子串中找长度更小的子串，直到找到匹配的子串或k = -1
		{
			k = n[k];
			j--;
		}
	}
	return pat.length();
}

int KMP(string pat,int k)
{
	int posP = 0;
	int posT = k;
	int lengthP = pat.length();
	int lengthT = target.length();

	while(posP < lengthP && posT < lengthT)
	{
		if(posP == -1 || pat[posP] == target[posT])
		{
			posP++;
			posT++;
		}
		else posP = n[posP];
	}
	if(posP < lengthP) return -1;
	else return posT - lengthP;
}

int main()
{
	cin >> s;
	n = new int[s.length()+1];
	getNext(s);
	cout << KMP(s,0) << endl;
	return 0;
}
