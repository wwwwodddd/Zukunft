#include<stdio.h>
#include<string.h>
char s[8][7]={"000000","000111","101010","101101","010010","010101","111000","111111"};
int z[8]={1,2,1,4,2,1,2,2},o[8],i,j,n,c,x;
int main()
{
	while(scanf("%d%d",&n,&c)+1)
	{
		memset(o,1,sizeof(o));
		for(j=0;j<2;j++)
			while(scanf("%d",&x)&&x!=-1)
				for(i=0;i<8;i++)
					if(s[i][x%6]==j+'0')
						o[i]=0;
		for(i=0;i<8;i++)
			if(o[i]&&(c>=z[i]||(c==1&&i==3)))
			{
				for(j=1;j<=n;j++)
					printf("%c",s[i][j%6]);
				printf("\n");
			}
	}
	return 0;
}
