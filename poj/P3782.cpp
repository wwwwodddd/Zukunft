#include<stdio.h>
int a[1020];
int s[1020];
int main()
{
	int i,j;
	int x,n,f,sum,t;
	scanf("%d",&f);
	while(f--)
	{
		scanf("%d %d",&x,&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			s[i]=s[i-1]+a[i];
		}
		for(i=1;i<=n;i++)
			if(s[n]%s[i]==0)
			{
				j=i;
				t=s[i]+s[i];
				while(j++&&j<=n)
				{
					if(s[j]==t)
						t+=s[i];
					else if(s[j]>t)
						goto end;
				}
				if(j==n+1&&s[n]==t+s[i]);
				{	
					printf("%d %d\n",x,s[i]);
					break;
				}
			end:;
			}
	}
	return 0;
}