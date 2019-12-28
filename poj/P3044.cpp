#include<stdio.h>
int s[50020]={-1};
int i,n,x,t,k,ans;
int main()
{
	scanf("%d%*d",&n);
	for(i=0;i<=n;i++)
	{
		if(i<n)
			scanf("%*d%d",&x);
		else
			x=0;
		while(x<s[k])
		{
			k--;
			ans++;
		}
		if(x!=s[k])
			s[++k]=x;
	}
	printf("%d\n",ans);
	return 0;
}
