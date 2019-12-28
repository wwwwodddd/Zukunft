#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
char p[1000010];
int a[1000010];
int l,m,n,i,j,k,q,ans;
int main()
{
while(cin >> m&&m!=0)
	{
	cin>>p+1;
	memset(a,0,sizeof(a));
	a[1]=0;
	k=0;
	for(q=2;q<=m;q++)
		{
		while(k>0&&p[k+1]!=p[q])
			k=a[k];
		if(p[k+1]==p[q])
			k++;
		a[q]=k;
		}
	printf("Test case #%d\n",++ans);
	for(i=1;i<=m;i++)
		if((i%(i-a[i]))==0&&a[i]!=0)
			printf("%d %d\n",i,i/(i-a[i]));
	printf("\n");
	}
return 0;
}
