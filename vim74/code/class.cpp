#include<cstdlib>
#include<cstdio>

using namespace std;

class T
{
	public:
		void print()
		{
			printf("%d %d %d\n",num[1],num[2],num[3]);
		}
	private:
		int num[4];
};

T sb;

int main()
{
	int i,j,k;
	scanf("%d%d%d",&i,&j,&k);
	//T sb(i,j,k);
	//sb.(i,j,k);
	sb.print();
	return 0;
}
