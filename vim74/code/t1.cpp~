#include<cstdio>
#include<cstring>

using namespace std;

char str[1000010];

int main()
{
    scanf("%s",str);
    int len = strlen(str);
    for (int i = 0; i < len-1; ++i)
        if (str[i] == '0' && str[i+1] =='k')
        {
            int j;
			i++;
			if (i + 1 == len) break;
            if (!((str[i+1]>= '0' && str[i+1] <= '9') || (str[i+1]>= 'A'&&str[i+1]<='E'))) continue;
            for (j = 1; j < len-i; ++j)
			{
                if (!((str[i+j]>= '0' && str[i+j] <= '9') || (str[i+j]>= 'A'&&str[i+j]<='E'))) break;
				if (j == 2 && str[i+1] == '0') break;
			}
            for (int k = i-1; k < i+j; ++k)
                printf("%c",str[k]);
            printf("\n");
			i = i+j;
        }
    return 0;
}

