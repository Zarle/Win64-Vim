#include<cstdio>

union NUM {
 int a;
 char b;
} num;

int main( )
{
 num.a = 0xff;
 if(num.b != 0xff)
     printf("%x",num.b);
 else
     printf("smallend");
 return 0;
}
