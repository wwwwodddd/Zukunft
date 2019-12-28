#include<stdio.h>
#include<iostream>
using namespace std;
int n,m;
char s[120][120];
int ok(char c)
{
	int xn,yn,xm,ym,cnt;
	xn=yn=0xffff;
	xm=ym=cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]==c)
			{
				xn=min(xn,i);
				xm=max(xm,i);
				yn=min(yn,j);
				ym=max(ym,j);
				cnt++;
			}
	for(int i=xn+1;i<=xm-1;i++)
		for(int j=yn+1;j<=ym-1;j++)
			if(s[i][j]!='.')
				return 0;
	if(xm==xn&&ym==yn)
		return cnt==1;
	return cnt==(xm-xn+1)*(ym-yn+1)-(xm-xn-1)*(ym-yn-1);
}
int main()
{
	for(;scanf("%d %d",&n,&m),n+m;)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>s[i][j];
		for(char i='A';i<='Z';i++)
			if(ok(i))
				printf("%c",i);
		puts("");
	}
}
