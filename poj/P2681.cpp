#include<stdio.h>
#include<string.h>
char a[100],b[100];
int n,la,lb,A[30],B[30],i,ans,k;
int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		ans=0;
		gets(a);
		gets(b);
		la=strlen(a);
		lb=strlen(b);
		for(i=0;i<la;i++)
			A[a[i]-'a']++;
		for(i=0;i<lb;i++)
			B[b[i]-'a']++;
		for(i=0;i<26;i++)
			ans+=min(A[i],B[i]);
		printf("Case #%d:  %d\n",++k,la+lb-ans*2);
	}
}