#include<stdio.h>
int main()
{
int n,x,y,q,w;
scanf("%d",&n);
while(n--)
	{
	scanf("%d %d",&x,&y);
	if(x<y||((x+y)&1)==1)
		{
		printf("impossible\n");
		continue;
		}
	q=x+y;
	w=x-y;
	printf("%d %d\n",q>>1,w>>1);
	}
return 0;
}