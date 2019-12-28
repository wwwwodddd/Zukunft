#include<stdio.h>
#include<string.h>
int a[30]={0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2};
char c[200];
int main()
{
	int i,j,k;
	while(scanf("%s",c)!=EOF)
	{
		int l=strlen(c);
		k=0;
		for(i=0;i<l;i++)
			if(k!=a[c[i]-'A'])
				if(k=a[c[i]-'A'])
					printf("%d",k);
		printf("\n");
	}
	return 0;
}