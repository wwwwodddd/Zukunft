#include<stdio.h>
#include<string.h>
#include<iostream>
#include<math.h>
using namespace std;
int wa[200000],wb[200000],wv[200000],w[200000];
char s[200000];
int r[200000],sa[200000];
int cmp(int *r,int a,int b,int l)
{
	return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int *r,int *sa,int n,int m)
{
	int i,j,p,*x=wa,*y=wb,*t;
	for(i=0;i<m;i++)
		w[i]=0;
	for(i=0;i<n;i++)
		w[x[i]=r[i]]++;
	for(i=1;i<m;i++)
		w[i]+=w[i-1];
	for(i=n-1;i>=0;i--)
		sa[--w[x[i]]]=i;
	for(j=1,p=1;p<n;j*=2,m=p)
	{
		for(p=0,i=n-j;i<n;i++)
			y[p++]=i;
		for(i=0;i<n;i++)
			if(sa[i]>=j)
			{
				y[p++]=sa[i]-j;
			}
		for(i=0;i<n;i++)
			wv[i]=x[y[i]];
		for(i=0;i<m;i++)
			w[i]=0;
		for(i=0;i<n;i++)
			w[wv[i]]++;
		for(i=1;i<m;i++)
			w[i]+=w[i-1];
		for(i=n-1;i>=0;i--)
			sa[--w[wv[i]]]=y[i];
		for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
	}
	return;
}
int rk[200000],height[200000];
void calheight(int *r,int *sa,int n)
{
	int i,j,k=0;
	for(i=1;i<=n;i++)
		rk[sa[i]]=i;
	for(i=0;i<n;height[rk[i++]]=k)
		for(k?k--:0,j=sa[rk[i]-1];r[i+k]==r[j+k];)
			k++;
	return;
}
int i,n,m,ans,N;
int z[200000],zz;
int len[1000];
int v[1000];
int ll,rr,cnt,lth;
int check(int x)
{
	int i,j,re=0;
	zz=0;
	memset(v,0,sizeof(v));
	for(i=1;i<=n+1;i++)
	{
		if(height[i]>=x)
		{
			for(j=1;j<=N;j++)
				if(sa[i]>=len[j-1]&&sa[i]<=len[j])
				{
					z[zz]=sa[i];
					v[j]++;
					break;
				}
		}
		else
		{
			cnt=0;
			for(j=1;j<=N;j++)
				if(v[j]>0)
					cnt++;
			if(cnt>N/2)
				zz++;
			memset(v,0,sizeof(v));
			for(j=1;j<=N;j++)
				if(sa[i]>=len[j-1]&&sa[i]<=len[j])
				{
					v[j]++;
					break;
				}
		}
	}
	return zz;
}
int work()
{
	ll=0;
	rr=1000;
	while(ll<rr)
	{
		if(check((ll+rr+1)/2))
			ll=(ll+rr+1)/2;
		else
			rr=(ll+rr+1)/2-1;
	}
	return ll;
}
int main()
{
	int i,j;
	while(scanf("%d",&N),N)
	{
		if(N==1)
		{
			scanf("%s",s);
			puts(s);
			continue;
		}
		cnt=lth=0;
		for(i=1;i<=N;i++)
		{
			s[len[i-1]]=i;
			scanf("%s",s+len[i-1]+1);
			for(j=len[i-1]+1;s[j];j++)
				s[j]+=4;
			len[i]=j;
		}
		n=strlen(s);
		for(i=0;i<n;i++)
			r[i]=s[i]+5;
		r[n]=0;
		da(r,sa,n+1,1000);
		calheight(r,sa,n);
		lth=work();
		check(lth);
		if(lth>0)
			for(i=0;i<zz;i++)
			{
				for(j=0;j<lth;j++)
					printf("%c",s[z[i]+j]-4);
				printf("\n");
			}
		else
			printf("?\n");
		puts("");
	}
	return 0;
}