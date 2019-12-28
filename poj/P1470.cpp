#include<stdio.h>
int t[1000020],p[1000020];
int h[1020],q[1020],f[1020],s[1020],v[1020];
int i,j,k,c,e,n;
int F(int x)
{
	if(f[x]==x)
		return x;
	return f[x]=F(f[x]);
}
int tarjan(int x)
{
	int i;
	for(i=q[x];i;i=p[i])
		if(v[t[i]])++s[F(t[i])];
	v[f[x]=x]=1;
	for(i=h[x];i;i=p[i])
		if(!v[t[i]])tarjan(t[i]),f[t[i]]=x;
	return 0;
}
inline bool get(int &a)
{
	char c;
	while(((c=getchar())<'0'||c>'9')&&c!=EOF);
	if(c==EOF)return 0;
	for(a=0;c>='0'&&c<='9';c=getchar())a=a*10+c-'0';
	return 1;
}
int main()
{
	while(get(n))
	{
		for(i=1;i<=n;++i)s[i]=h[i]=q[i]=f[i]=v[i]=0;
		for(c=e=1;c<=n;++c)
		{
			get(i),get(k);
			while(k--)get(j),++f[t[e]=j],p[e]=h[i],h[i]=e++;
		}
		get(k);
		while(k--)
		{
			get(i),get(j);
			t[e]=j,p[e]=q[i],q[i]=e++;
			t[e]=i,p[e]=q[j],q[j]=e++;
		}
		for(i=1;i<=n;++i)
			if(!f[i])tarjan(i);
		for(i=1;i<=n;++i)
			if(s[i])printf("%d:%d\n",i,s[i]);
	}
	return 0;
}
