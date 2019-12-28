#include<stdio.h>
#include<string.h>
int l,t,i,j,k;
char c[1020];
int main()
{

	scanf("%d",&t);
	while(t--)
	{
		k=1;
		scanf("%s",c);
		l=strlen(c);
		for(i=0;i<l;i++)
			if(c[i]==c[i+1])
				k++;
			else
			{
				printf("%d%c",k,c[i]);
				k=1;
			}
		printf("\n");
	}
	return 0;
}