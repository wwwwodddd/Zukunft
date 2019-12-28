#include<stdio.h>
#include<string.h>
#include<math.h>
int n,m,z,i,j,k;
char c[10],s[10];
int main()
{
	while(scanf("%s %d %d",c,&n,&m)+1)
	{
		j=0;
		for(i=0;i<strlen(c);i++)
			if(c[i]>='0'&&c[i]<='9')
				j=j*n+c[i]-'0';
			else if(c[i]>='A'&&c[i]<='Z')
				j=j*n+c[i]-'A'+10;
		if(j>=pow(1.*m,7))
			printf("  ERROR");
		else if(j==0)
			printf("      0");
		else
		{
			k=0;
			while(j!=0)
			{
				z=j%m;
				if(z<=9)
					s[k++]=z+'0';
				else
					s[k++]=z-10+'A';
				j/=m;
			}
			for(i=7;i>k;i--)
				putchar(' ');
			for(i=k-1;i>=0;i--)
				putchar(s[i]);
		}
		printf("\n");
	}
	return 0;
}
