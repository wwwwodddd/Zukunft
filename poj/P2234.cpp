#include<stdio.h>
int main()
{
	int i,n,ans,x;
	while(scanf("%d",&n)+1)
	{
		ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			ans^=x;
		}
		printf("%s\n",ans==0?"No":"Yes");
	}
	return 0;
}