#include <iostream>
#include <cstring>

using namespace std;

string target = "abcabbaba";//Ŀ���ַ���
string s;
int *n;

int getNext(string pat)//�õݹ��㷨��next����
{
	int k = -1;
	n[0] = -1;//�ݹ�ĳ�ʼ״̬
	for(int j = 0;j < pat.length();j++)
	{
		if(k == -1 || pat[j] == pat[k])//�����ǰǰ׺�Ӵ�����һ���ַ����׺�Ӵ�����һ���ַ���ͬ����next��j+1��= next��j��+ 1
		{
			k++;
			n[j+1] = k;
		}
		else//�����ǰǰ׺�Ӵ�����һ���ַ����׺�Ӵ�����һ���ַ���ͬ�������Ӵ����ҳ��ȸ�С���Ӵ���ֱ���ҵ�ƥ����Ӵ���k = -1
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
