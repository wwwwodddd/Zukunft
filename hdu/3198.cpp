#include<stdio.h>
char s[5020][30];
char c[30];
int n,m,z;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%s",s[i]);
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		z=0;
		scanf("%s",c);
		for(int l,j=0;j<n;j++)
		{
			l=0;
			for(int k=0;s[j][k];k++)
				if(s[j][k]==c[l])
					l++;
			z+=!c[l];
		}
		printf("%d\n",z);
	}
}
