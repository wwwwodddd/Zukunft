#include<stdio.h>
#include<string.h>
#include<iostream>
#include<math.h>
using namespace std;
int wa[200020],wb[200020],wv[200020],w[200020];
char c[200020];
int r[200020],sa[200020];
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
int rk[200020],height[200020];
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
int i,n,m,k;
int s[200020],ss;
int v[200020];
int a[200020];
int b[200020];
int l;
long long ans,ca,cb;
int main()
{
	int i,j;
	while(scanf("%d",&k),k)
	{
		scanf("%s",c);
		l=strlen(c);
		c[l]=1;
		scanf("%s",c+l+1);
		n=strlen(c);
		for(i=0;i<n;i++)
			r[i]=c[i];
		r[n]=0;
		da(r,sa,n+1,128);
		calheight(r,sa,n);
		for(i=2;i<=n;i++)
		{
			v[i]=(sa[i]<l?1:0);
			height[i]-=k-1;
			if(height[i]<0)
				height[i]=0;
		}
		a[0]=-1;
		long long ans=0;
		for(int t=0;t<=1;t++)
		{
			for(long long c=0,ss=0,i=2;i<=n;i++)
			{
				if(v[i]!=t)
					ans+=ss;
				c++;
				a[c]=height[i+1];
				b[c]=v[i]==t;
				ss+=(long long)a[c]*b[c];
				while(a[c-1]>=a[c])
				{
					ss-=(long long)(a[c-1]-a[c])*b[c-1];
					a[c-1]=a[c];
					b[c-1]+=b[c];
					c--;
				}
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}