#include<stdio.h>
#include<string.h>
char s[10010][80];
char a[80];
int p[10010],f[80];
int i,j,x,y,r,c;
int main()
{
	scanf("%d%d",&r,&c);
	for(i=0;i<r;i++)
	{
		scanf("%s",s[i]);
		strcpy(a,s[i]);
		for(j=c-1;j>0;j--)
		{
			a[j]=0;
			for(x=0,y=0;s[i][y];x++,y++)
			{
				if(!a[x])
					x=0;
				if(a[x]!=s[i][y])
					break;
			}
			if(!s[i][y])
				f[j]++;
		}
	}
	for(i=0;i<c;i++)
		if(f[i]==r)
			break;
	x=i;
	for(i=0;i<r;i++)
		s[i][x]=0;
	p[0]=-1;
	for(i=1,j=-1;i<r;i++)
	{
		while(j!=-1&&strcmp(s[j+1],s[i]))
			j=p[j];
		if(!strcmp(s[j+1],s[i]))
			j++;
		p[i]=j;
	}
	printf("%d\n",(r-1-p[r-1])*x);
	return 0;
}