//DNF
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
double px[60],py[60],pz[60],r[60],t[60];
double X,Y,Z,x,y,z,vx,vy,vz,dx,dy,dz,a,b,c,d,mnt,len;
double eps=1e-8;
int v[60];
int n,cur;
int sgn(double x)
{
	return x<-eps?-1:x>eps;
}
int main()
{
	scanf("%d",&n);
	fo(i,n)
		scanf("%lf %lf %lf",px+i,py+i,r+i);
	scanf("%lf %lf %lf %lf",&x,&y,&vx,&vy);
	vx-=x,vy-=y,vz-=z;
	for(int i=0;i<=10;i++)
	{
		memset(v,0,sizeof v);
		memset(t,0,sizeof t);
		fo(j,n)
		{
			X=x-px[j];
			Y=y-py[j];
			Z=z-pz[j];
			a=vx*vx+vy*vy+vz*vz;
			b=2*(X*vx+Y*vy+Z*vz);
			c=X*X+Y*Y+Z*Z-r[j]*r[j];
			d=b*b-4*a*c;
			if(sgn(d)>=0)
			{
				d=sqrt(d);
				t[j]=(-b-d)/(2*a);
				if(sgn(t[j])>0)
					v[j]=1;
			}
		}
		cur=0;
		mnt=0;
		fo(j,n)
			if(v[j])
				if(!cur||t[j]<mnt)
					mnt=t[cur=j];
		if(!cur)
			break;
		if(i)
			printf(" ");
		if(i==10)
		{
			printf("...");
			break;
		}
		printf("%d",cur);
		x+=mnt*vx;
		y+=mnt*vy;
		z+=mnt*vz;
		dx=x-px[cur];
		dy=y-py[cur];
		dz=z-pz[cur];
		len=2*(dx*vx+dy*vy+dz*vz)/(dx*dx+dy*dy+dz*dz);
		vx-=len*dx;
		vy-=len*dy;
		vz-=len*dz;
	}
	puts("");
}
