#include<stdio.h>
#include<math.h>
double pi=acos(-1.0);
double xa,xb,ya,yb,za,zb;
double uad,uam,ubd,ubm,vad,vam,vbd,vbm,ua,ub,va,vb;
char cau[2],cav[2],cbu[2],cbv[2];
int main()
{
	scanf("%lf %lf %s %lf %lf %s",&uad,&uam,cau,&vad,&vam,cav);
	scanf("%lf %lf %s %lf %lf %s",&ubd,&ubm,cbu,&vbd,&vbm,cbv);
	ua=(uad+uam/60)*pi/180;
	va=(vad+vam/60)*pi/180;
	ub=(ubd+ubm/60)*pi/180;
	vb=(vbd+vbm/60)*pi/180;
	if(*cau=='S')
		ua=-ua;
	if(*cbu=='S')
		ub=-ub;
	if(*cav=='W')
		va=-va;
	if(*cbv=='W')
		vb=-vb;
	xa=cos(ua)*cos(va);
	ya=cos(ua)*sin(va);
	za=sin(ua);
	xb=cos(ub)*cos(vb);
	yb=cos(ub)*sin(vb);
	zb=sin(ub);
	printf("%.3lf\n",acos(xa*xb+ya*yb+za*zb)*6370);
	return 0;
}