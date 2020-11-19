#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,z,p=1000000007;
struct P{
	int x,y,z;
	void scan(){
		scanf("%d %d",&x,&y);
	}
	bool operator<(const P&a)const{
		return x<a.x||x==a.x&&y<a.y;
	}
}a[100020];
int y[100020];
int f[100020];
int g[100020];
int v[100020];
int c[100020];
int d[100020];
void R(int *c,int x,int y){
	for(x++;x<=m;x+=x&-x)
		c[x]+=y,c[x]>=p?c[x]-=p:0;
}
int G(int *c,int x){
	int _=0;
	for(x++;x;x-=x&-x)
		_+=c[x],_>=p?_-=p:0;
	return _;
}
void work(){
	for(int i=1;i<=m;i++)
		c[i]=0;
	for(int j,i=0;i<n;i=j){
		for(j=i;j<n&&a[j].x==a[i].x;j++)
			v[j]=G(c,a[j].y);
		for(j=i;j<n&&a[j].x==a[i].x;j++)
			R(c,a[j].y,1);
	}
	for(int i=1;i<=m;i++)
		d[i]=c[i]=0;
	for(int j,i=0;i<n;i=j){
		for(j=i;j<n&&a[j].x==a[i].x;j++)
			f[j]=(G(c,a[j].y-1)-(long long)v[j]*(v[j]-1)/2+G(d,a[j].y))%p,f[j]<0?f[j]+=p:0;
		for(j=i;j<n&&a[j].x==a[i].x;j++)
		{
			R(c,a[j].y,i-v[j]);
			R(d,a[j].y,j-i+v[j]);
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		a[i].scan(),y[i]=a[i].y;
	sort(a,a+n);
	sort(y,y+n);
	m=unique(y,y+n)-y;
	for(int i=0;i<n;i++)
		a[i].y=lower_bound(y,y+m,a[i].y)-y;
	work();
	memcpy(g,f,sizeof g);
	memset(f,0,sizeof f);
	for(int i=0;i<n;i++)
		a[i].x=-a[i].x,a[i].z=i;
	sort(a,a+n);
	work();
	for(int i=0;i<n;i++)
		z=(z+(long long)f[i]*g[a[i].z])%p;
	printf("%d\n",z);
	return 0;
}
