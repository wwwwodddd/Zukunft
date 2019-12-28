#include<iostream>
#include<math.h>
using namespace std;
const double pi=acos(-1.0);
const double r=6875/2.0;
char s[200],o[100];
double dis(double va,double ua,double vb,double ub)
{
	ua*=pi/180;
	ub*=pi/180;
	return r*acos(cos(ua)*cos(ub)*cos((va-vb)*pi/180)+sin(ua)*sin(ub));
}
int main()
{
	int d,f,m;
	double ua,va,ub,vb;
	while(scanf("%s",s)&&s[0]=='M')
	{
		gets(s);
		gets(s);
		gets(s);
		gets(s);
		sscanf(s,"%d^%d'%d\" %s",&d,&f,&m,o);
		if(o[0]=='N')
			ua=(d+f/60.0+m/3600.0);
		else
			ua=-(d+f/60.0+m/3600.0);
		gets(s);
		sscanf(s,"and %d^%d'%d\" %s",&d,&f,&m,o);
		if(o[0]=='E')
			va=(d+f/60.0+m/3600.0);
		else
			va=-(d+f/60.0+m/3600.0);
		gets(s);
		gets(s);
		sscanf(s,"%d^%d'%d\" %s",&d,&f,&m,o);
		if(o[0]=='N')
			ub=(d+f/60.0+m/3600.0);
		else
			ub=-(d+f/60.0+m/3600.0);
		gets(s);
		sscanf(s,"and %d^%d'%d\" %s",&d,&f,&m,o);
		if(o[0]=='E')
			vb=(d+f/60.0+m/3600.0);
		else
			vb=-(d+f/60.0+m/3600.0);
		double l=dis(va,ua,vb,ub);
		printf("The distance to the iceberg: %.2lf miles.\n",l);
		if((int)(l+0.005)<100)
			puts("DANGER!");
	}
	return 0;
}