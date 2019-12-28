#include<stdio.h>
int ans,n,t,i,x,y;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ans=y=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			ans^=x;
			if(x>1)
				y=1;
		}
		if(y==0)
			ans^=1;
		if(ans==0)
			printf("%s\n","Brother");
		else
			printf("%s\n","John");
	}
	return 0;
}