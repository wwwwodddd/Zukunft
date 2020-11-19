#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<set>
#define BUFSIZE 10000000
char buf[BUFSIZE],*pt=buf;
#define X first
#define Y second
#define scan(t)\
{\
	t=0;\
	while(*pt<'0'||*pt>'9')\
		pt++;\
	while(((*pt)>='0'&&(*pt)<='9'))\
	t=t*10+*pt++-'0';\
}
#define scan_str(s)\
{ \
	int p=0;\
	while(*pt==' '||*pt=='\n')\
		pt++;\
	while(!(*pt==' '||*pt=='\n'))\
		s[p++]=*pt++;\
	s[p]=0;\
}
using namespace std;
typedef int ll;
typedef pair<int,int> ii;
struct N
{
	int k,x1,x2,y1,y2;
}a[350020];
int *l[50020];
int n,m,p[50020],w[50020],cnt[50020];
struct D
{
	ll*c[50020];
	void init()
	{
		for(int i=1;i<=n;i++)
		{
			c[i]=new ll[cnt[i]+1];
			memset(c[i]+1,0,4*cnt[i]);
		}
	}
	void R(int x,int y,int z)
	{
		for(;x<=n;x+=x&-x)
			for(int i=lower_bound(l[x],l[x]+cnt[x],y)-l[x]+1;i<=cnt[x];i+=i&-i)
				c[x][i]+=z;
	}
	ll G(int x,int y)
	{
		ll re=0;
		for(;x;x-=x&-x)
			for(int i=upper_bound(l[x],l[x]+cnt[x],y)-l[x];i;i-=i&-i)
				re+=c[x][i];
		return re;
	}
	ll Q(int x,int y)
	{
		return G(y,x-1)-G(x-1,x-1);
	}
}T;
set<ii>s;
set<ii>::iterator it,ti;
void ins2(int x,int y)
{
	for(;x<=n;x+=x&-x)
		l[x][cnt[x]++]=y;
}
int main()
{
	fread(buf,1,BUFSIZE,stdin);
	int q;
	scan(n);
	scan(q);
	for(int i=1;i<=n;i++)
	{
		scan(w[i])
		s.insert(ii(w[i],i));
		it=s.lower_bound(ii(w[i],i));
		if(it==s.begin()||(--it)->X<w[i])
			p[i]=0;
		else
			p[i]=it->Y;
		a[i].k=i,a[i].x2=p[i],a[i].y2=w[i];
	}
	m=n+1;
	for(;q--;)
	{
		char o[5];
		int x,y;
		scan_str(o);
		scan(x);
		scan(y);
		if(*o=='Q')
			a[m].k=-1,a[m].x1=x,a[m++].y1=y;
		else
		{
			ti=it=s.lower_bound(ii(w[x],x));
			if(it!=--s.end()&&(++it)->X==w[x])
				a[m].k=it->Y,a[m].x1=p[it->Y],a[m].y1=a[m].y2=w[it->Y],a[m++].x2=p[it->Y]=p[x];
			s.erase(ti);
			s.insert(ii(y,x));
			ti=it=s.lower_bound(ii(y,x));
			a[m].k=x,a[m].x1=p[x],a[m].y1=w[x],a[m].y2=w[x]=y;
			if(it==s.begin()||(--it)->X<y)
				a[m++].x2=p[x]=0;
			else
				a[m++].x2=p[x]=it->Y;
			if(ti!=--s.end()&&(++ti)->X==y)
				a[m].k=ti->Y,a[m].x1=p[ti->Y],a[m].y1=a[m].y2=w[ti->Y],a[m++].x2=p[ti->Y]=x;
		}
	}
	for(int i=1;i<m;i++)
		if(a[i].k!=-1)
			cnt[a[i].k]++;
	for(int i=1;i<=n;i++)
		if(i+(i&-i)<=n)
			cnt[i+(i&-i)]+=cnt[i];
	for(int i=1;i<=n;i++)
		l[i]=new int[cnt[i]],cnt[i]=0;
	for(int i=1;i<m;i++)
		if(a[i].k!=-1)
			ins2(a[i].k,a[i].x2);
	for(int i=1;i<=n;i++)
		sort(l[i],l[i]+cnt[i]),cnt[i]=unique(l[i],l[i]+cnt[i])-l[i];
	T.init();
	for(int i=1;i<=n;i++)
		T.R(a[i].k,a[i].x2,1);
	for(int i=n+1;i<m;i++)
		if(a[i].k==-1)
			printf("%d\n",T.Q(a[i].x1,a[i].y1));
		else
			T.R(a[i].k,a[i].x1,-1),T.R(a[i].k,a[i].x2,1);
	return 0;
}
