#include<stdio.h>
#include<string.h>
char c[50020];
int f[50020],i,j,k,l;
int main()
{
	while(scanf("%s",c+1)&&c[1]!='0')
	{
		l=strlen(c+1);
		f[l+1]=1;
		for(i=l;i>0;i--)
		{
			f[i]=0;
			if(c[i]=='0')
				continue;
			if(i!=l&&((c[i]-'0')*10+(c[i+1]-'0')<=26))
				f[i]+=f[i+2];
			f[i]+=f[i+1];
		}
		printf("%d\n",f[1]);
	}
	return 0;
}