#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<vector>
#include<cmath>
using namespace std;
vector<int> vec[100005];
int f[500][500],c[100005],a[100005],L,vis[500005],m,cnt1[100005],cnt2[100005],
	q[100005];
void init(int N)
{
	L=sqrt((double)N);
	for(int i=0;i<=N;i++)
		if(i%L==0)
		{
			int j=i/L,cnt=0;
			memset(c,0,sizeof(c));
			for(int k=i;k<=N;k++)
			{
				if(k%L==0)
					f[j][k/L]=cnt;
				c[a[k]]++;
				if(c[a[k]]>1)	if(c[a[k]]&1)	cnt--;else cnt++;
			}
		}
}
int getcnt(int num,int l,int r)
{
	if(l>r)	return 0;
	return upper_bound(vec[num].begin(),vec[num].end(),r)-
		lower_bound(vec[num].begin(),vec[num].end(),l);
}
int brute(int l,int r)
{
	int tail=0,ret=0;
	for(int i=l;i<=r;i++)
		if(vis[a[i]]!=m)
		{
			vis[a[i]]=m;
			q[tail++]=a[i];
			cnt1[a[i]]=1;
		}else	cnt1[a[i]]++;
	for(int i=0;i<tail;i++)	if(cnt1[q[i]]>1&&(cnt1[q[i]]&1)==0)	ret++;
	return ret;
}
int ask(int l,int r)
{
	if(r-l<=L)	return brute(l,r);
	int b=l/L+(l%L!=0),e=r/L;
	int ret=f[b][e],tail=0;
	for(int i=l;i%L!=0;i++)
		if(vis[a[i]]!=m)
		{
			q[tail++]=a[i];
			vis[a[i]]=m;
			cnt1[a[i]]=1;
			cnt2[a[i]]=getcnt(a[i],L*b,L*e-1);
		}else	cnt1[a[i]]++;
	for(int i=L*(r/L);i<=r;i++)
		if(vis[a[i]]!=m)
		{
			q[tail++]=a[i];
			vis[a[i]]=m;
			cnt1[a[i]]=1;
			cnt2[a[i]]=getcnt(a[i],L*b,L*e-1);
		}else	cnt1[a[i]]++;
	for(int i=0;i<tail;i++)
	{
		int cnt_1=cnt1[q[i]]+cnt2[q[i]];
		int cnt_2=cnt2[q[i]];
		if((cnt_1&1)&& (!(cnt_2&1)) && cnt_2>0)	ret--;
		if((!(cnt_1&1))&&(cnt_1>0)&&((cnt_2&1)||cnt_2==0))	ret++;
	}
	return ret;
}

int main()
{
	freopen("c.in","r",stdin);
	freopen("s.out","w",stdout);
	int n,c,ans=0,l,r;
	scanf("%d%d%d",&n,&c,&m);
	for(int i=1;i<=n;i++)	scanf("%d",a+i),vec[a[i]].push_back(i);
	init(n);
	while(m--)
	{
//		cerr << m << endl;
		scanf("%d%d",&l,&r);
		l=(l+ans)%n+1,r=(r+ans)%n+1;
		if(l>r)	swap(l,r);
		ans=ask(l,r);
		printf("%d\n",ans);
	}
//	cerr << clock() << endl;
//	while(1);
	return 0;
}
