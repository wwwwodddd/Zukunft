#include <stdio.h>
#include <string.h>
#define INF 0xffff
int n,i,j,k,g[27][27];
double v[27],temp;
char c[5],s[30];
int main()
{
	while(scanf("%d",&n)+1)
	{
		memset(v,0,sizeof(v));
		memset(g,0x3f,sizeof(g));
		for (i=0;i<n;i++)
		{
			scanf("%s %lf %s",c,&temp,s);
			v[c[0]-'A']=temp;
			for(j=0;s[j];j++)
			{
				if(s[i]=='*')
					g[c[0]-'A'][26]=1;
				else
					g[c[0]-'A'][s[j]-'A']=1;
			}
		}
		for(k=0;k<=26;k++)
			for(i=0;i<=26;i++)
				for(j=0;j<=26;j++)
					if(g[i][j]>g[i][k]+g[k][j])
						g[i][j]=g[i][k]+g[k][j];
		for(i=1;i<=26;i++)
			for(j=1;j<g[i][26]&&j<30;j++)
				v[i]*=0.95;
		temp=0;
		j=0;
		for(i=0;i<26;i++)
			if(v[i]>temp)
			{
				temp=v[i];
				j=i;
			}
		printf("Import from %c\n",j+'A');
	}
	return 0;
}
