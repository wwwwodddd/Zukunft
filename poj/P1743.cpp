#include<stdio.h>
#include<string.h>
int wa[40020],wb[40020],wv[40020],ws[40020];
char s[40020];
int r[40020],sa[40020];
int cmp(int *r,int a,int b,int l)
{
	return r[a]==r[b]&&r[a+l]==r[b+l];
}
int min(int x,int y)
{
	return x<y?x:y;
}
int max(int x,int y)
{
	return x>y?x:y;
}
void da(int *r,int *sa,int n,int m)
{
	int i,j,p,*x=wa,*y=wb,*t;
	for(i=0;i<m;i++)
		ws[i]=0;
	for(i=0;i<n;i++)
		ws[x[i]=r[i]]++;
	for(i=1;i<m;i++)
		ws[i]+=ws[i-1];
	for(i=n-1;i>=0;i--)
		sa[--ws[x[i]]]=i;
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
			ws[i]=0;
		for(i=0;i<n;i++)
			ws[wv[i]]++;
		for(i=1;i<m;i++)
			ws[i]+=ws[i-1];
		for(i=n-1;i>=0;i--)
			sa[--ws[wv[i]]]=y[i];
		for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
	}
	return;
}
int rank[40020],height[40020];
void calheight(int *r,int *sa,int n)
{
	int i,j,k=0;
	for(i=1;i<=n;i++)
		rank[sa[i]]=i;
	for(i=0;i<n;height[rank[i++]]=k)
		for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];)
			k++;
	return;
}
int a[40020];
int i,N,n,ll,rr,mn,mx;
int check(int x)
{
	mn=sa[0];
	mx=sa[0];
	for(i=1;i<N;i++)
	{
		if(height[i]>=x)
		{
			mn=min(mn,sa[i]);
			mx=max(mx,sa[i]);
		}
		else
		{
			mn=sa[i];
			mx=sa[i];
		}
		if(mx-mn>x)
			return 1;
	}
	return 0;
}
int work()
{
	ll=0;
	rr=n;
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
	int ans;
	while(scanf("%d",&N),N)
	{
		n=N-1;
		for(i=0;i<N;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
			r[i]=a[i+1]-a[i]+100;
		da(r,sa,N,200);
		calheight(r,sa,n);
		ans=work();
		if(ans>1)
			printf("%d\n",ans+1);
		else
			printf("0\n");
	}
	return 0;
}
