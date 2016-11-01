#include<iostream>
#include<string>

using namespace std;

string inc(string s)
{
	int l=s.length();
	for(int i=s.length()-1;i>=0;i--)
	{
		if(s[i]<122)
		{
			s[i]++;
			for(int j=i;j<s.length()-1;j++)
			{
				s[j]=97;
			}
			return s;
		}
	}
	for(int j=0;j<l;j++)
	{
		s[j]=97;
	}
	return s.append("a");
}

int main()
{
	string str[30];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>str[i];
	string ans="a";
	for(int i=0;i<n;i++)
	{
		if(str[i].find(ans) != string::npos)
		{
			i=-1;
			ans=inc(ans);
		}
	}
	cout<<ans<<endl;
}

