#include<stdio.h>
#include<string.h>
#include<iostream>
#include<assert.h>
using namespace std;
char s[1000020];
int v[26],t[26];
int p[26][500020];
int c[1000020];
int n,i,j,k,z,cnt;
void R(int x,int y)
{
	for(;x<=n;x+=x&-x)
		c[x]+=y;
}
int G(int x)
{
	int re=0;
	for(;x;x-=x&-x)
		re+=c[x];
	return re;
}
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for(i=0;i<n;i++)
	{
		s[i]-='A';
		v[s[i]]++;
	}
	for(i=0;i<26;i++)
		z+=(v[i]&1);
	if(z>1)
	{
		printf("-1");
		return 0;
	}
	z=0;
	for(i=0;i<n;i++)
	{
		t[s[i]]++;
		if(t[s[i]]<=v[s[i]]/2)
		{
			p[s[i]][t[s[i]]]=++cnt;
			z+=i-G(cnt);
			R(cnt,1);
		}
		else if(v[s[i]]&1&&t[s[i]]==(v[s[i]]+1)/2)
		{
			p[s[i]][t[s[i]]]=(n+1)/2;
			z+=i-G((n+1)/2);
			R((n+1)/2,1);
		}
		else
		{
			k=n+1-p[s[i]][v[s[i]]+1-t[s[i]]];
			z+=i-G(k);
			assert(i-G(k)>=0);
			R(k,1);
		}
	}
	printf("%d",z);
	return 0;
}