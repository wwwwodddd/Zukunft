#include<math.h>
#include<stdio.h>
using namespace std;
int n;
double pi=3.1415926,x,y,z;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&x,&y);
		z=pi*(x*x+y*y)/2;
		printf("Property %d: This property will begin eroding in year %.f.\n",i,ceil(z/50));
	}
	puts("END OF OUTPUT.");
}
