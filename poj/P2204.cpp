#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int s[200010][3];
int a[1010],b[1010],v[1010];
int ansi,ans,ss,l,m,n;
int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int i,j,t,maxs,ts,td;
	scanf("%d %d",&l,&m);
	l*=2;
	for(i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
		a[i]*=2;
	}
	scanf("%d",&n);
	b[0]=0;
	for(i=1;i<n;i++)
	{
		scanf("%d",&b[i]);
		b[i]*=2;
	}
	maxs=l-b[n-1];
	ans=ansi=0;
	for(i=0;i<m;i++)
	{
		v[i]=0;
		for(j=1;j<n;j++)
			if(abs(a[i]-b[j])<abs(a[i]-b[v[i]]))
				v[i]=j;
		ans+=abs(a[i]-b[v[i]]);
	}
	ss=0;
	for(i=0;i<m;i++)
	{
		for(j=v[i]-1;j>=0;j--)
		{
			ts=a[i]-(b[j]+b[j+1])/2;
			if(ts<=maxs&&ts>=0)
			{
				s[ss][0]=ts,s[ss][1]=i,s[ss][2]=j;
				ss++;
			}
		}
	}
	qsort(s,ss,sizeof(s[0]),cmp);
	for(i=0;i<ss;)
	{
		for(ts=s[i][0];s[i][0]==ts&&i<ss;i++)
			v[s[i][1]]=s[i][2];
		for(j=0,td=0;j<m;j++)
			td+=abs(b[v[j]]+ts-a[j]);
		if(td>ans)
		{
			ans=td;
			ansi=ts;
		}
	}
	for(j=0,td=0;j<m;j++)
		td+=abs(b[v[j]]+maxs-a[j]);
	if(td>ans)
	{
		ans=td;
		ansi=maxs;
	}
	printf("%.1f %.1f\n",(double)ansi/2.0,(double)ans/2.0);
	return 0;
}
