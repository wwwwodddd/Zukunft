#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int d[10],sm;
char s[1020];
int x,f;
int D(int x)
{
	for(int i=0;i<10;i++)
		if(i%3==x&&d[i])
			return d[i]--,1;
	return 0;
}
int main()
{
	scanf("%s",s);
	for(int i=0;s[i];i++)
		d[s[i]-'0']++,sm+=s[i];
	sm%=3;
	if(!(d[0]+d[5]))
		puts("impossible");
	else
	{
		d[x=d[0]?0:5]--;
		if(sm)
			if(!D(sm)&&!(D(sm^3)&&D(sm^3)))
				return puts("impossible"),0;
		for(int i=9;~i;i--)
			while(d[i]--)
				printf(i+f?f=1,"%d":"",i);
		printf("%d\n",x);
	}
}
