#include<stdio.h>
#include<string.h>
#include<iostream>
#include<math.h>
using namespace std;
int wa[100010],wb[100010],wv[100010],w[100010];
char s[100010];
int r[100010],sa[100010];
int f[100010][20];
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
int rk[100010],height[100010];
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
void rmq(int n)
{
	int i,j;
	for(i=0;i<n;i++)
		f[i][0]=height[i];
	for(j=1;(1<<j)<=n;j++)
		for(i=0;i+(1<<j)-1<n;i++)
			f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}
int lcp(int i,int j)
{
	int x=rk[i],y=rk[j];
	if(x>y)
		swap(x,y);
	x++;
	int k=(int)(log((y-x)*1.0)/log(2.0));
	return min(f[x][k],f[y-(1<<k)+1][k]);
}
int i,n,m,ans,csc;
int z[100010],zz;
int work()
{
	int i,j,re,lc,dlt;
	ans=zz=0;
	for(i=1;i<=n/2;i++)
	{
		re=0;
		for(j=0;j+i<n;j+=i)
		{
			lc=lcp(j,j+i);
			re=max(re,lc/i+1);
			if(lc%i&&j)
			{
				dlt=i-lc%i;
				lc=lcp(j-dlt,j+i-dlt);
				re=max(re,lc/i+1);
			}
		}
		if(re>ans)
		{
			ans=re;
			zz=0;
			z[zz++]=i;
		}
		else if(re==ans)
			z[zz++]=i;
	}
	int st,l;
	for(i=1;i<n;i++)
	{
		for(j=0;j<zz;j++)
		{	
			if(lcp(sa[i],sa[i]+z[j])>=(ans-1)*z[j])
			{
				st=sa[i];
				l=ans*z[j];
				i=n;
				break;
			}
		}
	}
	printf("Case %d: ",++csc);
	for(i=0;i<l;i++)
		printf("%c",s[st+i]);
	printf("\n");

	return re;
}
int main()
{
	while(1)
	{
		memset(f,0,sizeof(f));
		scanf("%s",s);
		if(s[0]=='#')
			break;
		n=strlen(s);
		for(i=0;i<n;i++)
			r[i]=s[i];
		r[n]=0;
		da(r,sa,n+1,100010);
		calheight(r,sa,n);
		n++;
		rmq(n);
		work();
	}
	return 0;
}