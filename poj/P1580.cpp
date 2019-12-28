#include<stdio.h>
#include<string.h>
char sa[100020],sb[100020];
int la,lb;
int i,j,k,l;
int ans,len,g;
int solve()
{
	la=strlen(sa);
	lb=strlen(sb);
	int u,re=0;  
	for(i=0;i<la;i++)
		for(j=0;j<lb;j++)
		{
			u=0;
			for(k=i,l=j;k<la&&l<lb;k++,l++)
				if(sa[k]==sb[l])
					u++;
			if(re<u)
				re=u;
		}
	return re*2;
}
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	while(scanf("%s", sa)&& strcmp(sa,"-1") && scanf("%s", sb))
	{
		ans=solve();
		len=la+lb;
		printf("appx(%s,%s) = ",sa,sb);
		if (!ans)
			puts("0");
		else if (ans==len)
			puts("1");
		else
		{
			g=gcd(ans,len);
			printf("%d/%d\n",ans/g,len/g);
		}
	}
	return 0;
}
