#include<stdio.h>
#include<string.h>
int wa[1000010],wb[1000010],wv[1000010],ws[1000010];
char s[1000010];
int r[1000010],sa[1000010];
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
int rank[1000010],height[1000010];
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
int a[1000010];
int i,n,m,ll,rr,z;
int check(int x)
{
	for(i=1;i<n;i++)
	{
		if(height[i]>=x)
			z++;
		else
			z=1;
		if(z>=m)
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
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",&r[i]);
	for(i=0;i<n;i++)
		r[i]++;
	n++;
	da(r,sa,n,1000010);
	calheight(r,sa,n);
	printf("%d\n",work());
	return 0;
}