#include<stdio.h>
#include<algorithm>
using namespace std;
int x,y;
int main()
{
	while(scanf("%d %d",&x,&y)!=EOF)
		printf("%d\n",min(x,y)==int(abs(y-x)*1.618033988749)?0:1);
return 0;
}