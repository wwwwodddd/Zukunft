#include<stdio.h>
int d[6000],e[6000][3];
int n,g;
int search(int v)
{
	int i,j,k;
	for(i=0;i<v;i++)
		d[i]=0x3fffffff;
	d[1]=0;
	while(1)
	{
		k=1;
		for(j=0;j<v;j++)
			if(d[e[j][1]]>d[e[j][0]]+e[j][2])
			{
				d[e[j][1]]=d[e[j][0]]+e[j][2];
				k=0;
			}
		if(d[1]<0)
			return 1;
		if(k)
			return 0;
	}
}
int main()
{
	int w,m,f,i,j;
	scanf("%d",&f);
	while(f--)
	{
		scanf("%d %d %d",&n,&m,&w);
		j=0;
		for(i=0;i<m;i++)
		{
			scanf("%d %d %d",&e[j][0],&e[j][1],&e[j][2]);
			j++;
			e[j][0]=e[j-1][1];
			e[j][1]=e[j-1][0];
			e[j][2]=e[j-1][2];
			j++;
		}
		for(i=0;i<w;i++)
		{
			scanf("%d %d %d",&e[j][0],&e[j][1],&e[j][2]);
			e[j][2]=-e[j][2];
			j++;
		}
		printf("%s",search(j)==1?"YES\n":"NO\n");
	}
	return 0;
}