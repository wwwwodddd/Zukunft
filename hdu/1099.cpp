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
long long gcd(long long x,long long y)
{
	return y?gcd(y,x%y):x;	
}
long long up,dn,g;
int n;
int main()
{
	for(;scanf("%d",&n)+1;)
	{
		up=0,dn=1;
		for(int i=1;i<=n;i++)
		{
			up=up*i+n*dn;
			dn=dn*i;
			g=gcd(up,dn);
			up/=g;
			dn/=g;
		}
		if(up%dn==0)
			printf("%d\n",up/dn);
		else
		{
			static char su[77],sd[77],si[77];
			static char ss[77],sl[77];
			static char ws[]="                              ";
			static char ln[]="------------------------------";
			sprintf(su,"%d",up%dn);
			sprintf(si,"%d",up/dn);
			sprintf(sd,"%d",dn);
			memset(ss,0,sizeof(ss));
			strncpy(ss,ws,strlen(si));
			memset(sl,0,sizeof(sl));
			strncpy(sl,ln,max(strlen(su),strlen(sd)));
			printf("%s %s\n%s %s\n%s %s\n",ss,su,si,sl,ss,sd);
		}
	}
}
