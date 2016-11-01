#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>

using namespace std;

char s[510];
string ans[25000];
int cnt;

void deal()
{
	int l = strlen(s);
	string s1,s2;
	int t = 0;
	for (int i = 0; i <= l; ++i)
	{
		if (s[i] == ' ' || s[i] == '.' || s[i] == ',' || s[i] == '\0')
		{
			if (s2 != "") t=min(2,t+1);
			if (t == 2)
				ans[++cnt] = s1 + ' ' + s2;
			if (s[i] == ' ')
			{
				if (s2 != "")
				{
					s1 = s2;
					s2 = "";
				}
			}
			else
			{
				s1 = "";
				s2 = "";
				t = 0;
			}
			continue;
		}
		s2 += s[i];
	}

}

void work()
{
	sort(ans+1,ans+cnt+1);
	int f = 0;
	int cc = 0,pt = 0;
	for (int i = 1; i <= cnt; ++i)
	{
		if (ans[i]!=ans[i-1])
			cc = 1;
		else ++cc;
		if (cc > f)
		{
			f = cc;
			pt = i;
		}
	}
	cout<<ans[pt]<<':'<<f<<endl;
}

int main()
{
	while (gets(s))
	{
		if (s[0] == '#')
		{
			work();
			cnt = 0;
			continue;
		}
		deal();
	}
	return 0;

}
