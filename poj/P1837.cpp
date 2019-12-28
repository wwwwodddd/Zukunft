#include<stdio.h>
#include<string.h>
int f[20000];
int e[20000];
int h[30];
int main()
{
int n,m,x;
int i,j,k;
scanf("%d %d",&n,&m);
f[10000]=1;
for(i=0;i<n;i++)
	scanf("%d",&h[i]);
for(i=0;i<m;i++)
	{
	scanf("%d",&x);
	for(j=7000;j<13000;j++)
		if(f[j])
			{
			for(k=0;k<n;k++)
				e[j+h[k]*x]+=f[j];
			e[j+h[k]*x]+=f[j+h[k]*x];
			}
	for(j=7000;j<13000;j++)
	f[j]=e[j];
	memset(e,0,sizeof(e));
	}
printf("%d",f[10000]-1);
return 0;
}