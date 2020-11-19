#include<stdio.h>
#include<string.h>
char a[1020];
int f[1020],la;
char b[1020];
int g[1020],lb;
int ans[1020],ll;
int csc,k,i;
int main()
{
	scanf("%d",&csc);
	while(csc--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		memset(ans,0,sizeof(ans));
		printf("Case %d:\n",++k);
		scanf("%s %s",a,b);
		printf("%s + %s = ",a,b);
		la=strlen(a);
		lb=strlen(b);
		for(i=0;i<la;i++)
			f[la-i]=a[i]-'0';
		for(i=0;i<lb;i++)
			g[lb-i]=b[i]-'0';
		for(i=0;i<1010;i++)
			ans[i]=f[i]+g[i];
		for(i=0;i<1010;i++)
		{
			ans[i+1]+=ans[i]/10;
			ans[i]%=10;    
		}
		ll=1010;
		while(ans[ll]==0)
			ll--;
		for(i=ll;i>0;i--)
			printf("%d",ans[i]);
		if(csc!=0)
			printf("\n\n");
		else
			puts("");
	}
}
