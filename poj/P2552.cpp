#include<stdio.h>
int v[34000];
int ans[3000];
int p,i,j,n;
void Q()
{
	for(i=2;n<3000;i++)
		if(!v[i])
		{
			ans[n++]=i;
			for(j=i+1,p=0;j<34000;j++)
				if(!v[j]&&++p==i)
				{
					v[j]=1;
					p=0;
				}
		}
}
int main()
{
	Q();
	while(scanf("%d",&n)&&n)
		printf("%d\n",ans[n-1]);
	return 0;
}