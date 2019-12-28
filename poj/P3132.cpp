#include<stdio.h>
int p[1200],v[1200];
int f[1200][15];
int cnt,x,y,i,j,k;
int main()
{
	for(i=2;i<1200;i++)
	{
		if(!v[i])
			p[cnt++]=i;
		for(j=0;j<cnt&&p[j]*i<1200;j++)
		{
			v[i*p[j]]=1;
			if(i%p[j]==0)
				break;
		}
	}
	f[0][0]=1;
	for(i=0;i<cnt;i++)
		for(j=1200-p[i];j>=0;j--)
			for(k=1;k<=14;k++)
				f[j+p[i]][k]+=f[j][k-1];
	while(scanf("%d %d",&x,&y)&&x+y)
		printf("%d\n",f[x][y]);
	return 0;
}

