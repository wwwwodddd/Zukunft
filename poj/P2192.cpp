#include<stdio.h>
#include<string.h>
int f[410][410];
int n,i,j,k,la,lb,lc;
char a[410],b[410],c[410];
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		memset(f,0,sizeof(f));
		scanf("%s %s %s",a,b,c);
		la=strlen(a);
		lb=strlen(b);
		lc=strlen(c);
		if(la+lb!=lc)
		{
			printf("Data set %d: no\n",++k);
			continue;
		}
		f[0][0]=1;
		for(i=0;i<lc;i++)
			for(j=0;j<=i;j++)
				if(f[j][i-j])
				{
					if(a[j]==c[i])
						f[j+1][i-j]=1;
					if(b[i-j]==c[i])
						f[j][i-j+1]=1;
				}
		printf("Data set %d: %s\n",++k,f[la][lb]?"yes":"no");
	}
	return 0;
}