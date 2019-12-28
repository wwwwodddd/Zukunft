#include<stdio.h>
int n,l,h,ans;
int main()
{
freopen("C:\\c.in","r",stdin);
freopen("C:\\c1.out","w",stdout);
while(scanf("%d %d",&n,&l)!=EOF)
    {
	ans=0;
	while(n--)
		{
		scanf("%d",&h);
		ans=ans>(l-(h-1+l)%l-1)?ans:(l-(h-1+l)%l-1);

		}	
	printf("%d ",ans);
	}
return 0;
}