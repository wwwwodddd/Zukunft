#include<stdio.h>
#include<iostream>
using namespace std;
int a[3020],pa,b[3020],pb,c[3020],pc,X,Y,Z,k,n,m,p,q;
long long w[640][640],s[640][640],r[640][640],x[640][640],y[640][640],z[640][640],ans,_;
long long&ww(int X,int Y){return w[X][Y];}
long long&ss(int X,int Y){return s[X][Y];}
long long&rr(int X,int Y){return r[X][Y];}
long long&xx(int X,int Y){return x[X][Y];}
long long&yy(int X,int Y){return y[X][Y];}
long long&zz(int X,int Y){return z[X][Y];}
int main()
{
	scanf("%d",&pa);
	for(int i=0;i<pa;i++)
		scanf("%d",a+i);
	scanf("%d",&pb);
	for(int i=0;i<pb;i++)
		scanf("%d",b+i);
	scanf("%d",&pc);
	for(int i=0;i<pc;i++)
		scanf("%d",c+i);
	scanf("%d %d %d %d",&n,&m,&p,&q);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ww(i,j)=(a[i%pa]+a[j%pa]+b[i%pb]+b[j%pb]+c[i%pc]+c[j%pc])%p+1;
	for(int i=1;i<=n+5;i++)
		for(int j=0;j<=m+5;j++)
		{
			if(j)
			{
				ss(i,j)=ss(i,j-1)+ww(i,j);
				rr(i,j)=rr(i,j-1)+ss(i,j);
				yy(i,j)=yy(i-1,j-1)+rr(i,j);
			}
			xx(i,j)=xx(i-1,j)+rr(i,j);
			zz(i,j)=zz(i-1,j+1)+rr(i,j);
		}
	for(int i=1;i<=q;i++)
	{
		X=(a[i%pa]+a[1%pa]+b[i%pb]+b[1%pb]+c[i%pc]+c[1%pc])%n+1;
		Y=(a[i%pa]+a[2%pa]+b[i%pb]+b[2%pb]+c[i%pc]+c[2%pc])%m+1;
		k=min(min(X,Y),min(n-X+1,m-Y+1));
		Z=(a[i%pa]+a[3%pa]+b[i%pb]+b[3%pb]+c[i%pc]+c[3%pc])%k+1;
		_^=yy(X,Y+Z-1)-yy(X-Z,Y-1)+yy(X+Z-1,Y-2)-yy(X-1,Y-Z-2)+zz(X-1,Y-Z)-zz(X-Z,Y-1)+zz(X+Z-1,Y)-zz(X,Y+Z-1)-2*(xx(X+Z-1,Y-1)-xx(X-Z,Y-1));
	}
	printf("%lld",_);
	return 0;
}
