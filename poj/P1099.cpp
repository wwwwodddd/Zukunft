#include<stdio.h>
#include<string.h>
char c[60][60];
int i,j,m,z;
int Ox,Oy,t;
int main()
{
	for(z=1;scanf("%d",&m),m;++z)
	{
		memset(c,' ',sizeof(c));
		for(i=0;i<m*4-1;++i)
			c[i][0]=c[i][m*4+2]='*';
		for(j=0;j<m*4+3;++j)
			c[0][j]=c[m*4-2][j]='*';
		for(i=0;i<m;++i)
			for(j=0;j<m;++j)
				c[i*4+1][j*4+3]='O';
		for(i=1;i<m*4-2;i+=2)
			for(j=i%4;j<m*4+3;j+=4)
				c[i][j]='H';
		for(i=0;i<m;++i)
			for(j=0;j<m;++j)
			{
				Ox=i*4+1;
				Oy=j*4+3;
				scanf("%d",&t);
				if(t==1)
					c[Ox][Oy-1]=c[Ox][Oy+1]='-';
				else if(t==-1)
					c[Ox-1][Oy]=c[Ox+1][Oy]='|';
				else if(t==0)
				{
					if(c[Ox][Oy-3]!='-')
						c[Ox][Oy-1]='-';
					else
						c[Ox][Oy+1]='-';
					if(Ox-1>0&&c[Ox-3][Oy]!='|')
						c[Ox-1][Oy]='|';
					else
						c[Ox+1][Oy]='|';
				}
			}
		printf("Case %d:\n\n",z);
		for(i=0;i<m*4-1;++i)
		{
			for(j=0;j<m*4+3;++j)
				putchar(c[i][j]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
