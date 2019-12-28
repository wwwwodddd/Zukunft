#include<stdio.h>
char L(int x)
{
	if(x<26)
		return x+'A';
	return x-26+'a';
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d %d 2\n",n,n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%c",L(i));
		puts("");
		for(int j=0;j<n;j++)
			printf("%c",L(j));
		puts("\n");
	}
	return 0;
}
