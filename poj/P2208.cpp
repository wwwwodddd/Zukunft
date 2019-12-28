#include<math.h>
#include<stdio.h>
#define sqr(x) x*x
double ab,ac,ad,bc,bd,cd,p,p1,p2,p3,vol;
int main()
{
	while(scanf("%lf%lf%lf%lf%lf%lf",&ab,&ac,&ad,&bc,&bd,&cd)+1)
	{
		p1=sqr(ab*cd)*(-sqr(ab)+sqr(ac)+sqr(ad)-sqr(cd)+sqr(bd)+sqr(bc));
		p2=sqr(ac*bd)*(+sqr(ab)-sqr(ac)+sqr(ad)+sqr(cd)-sqr(bd)+sqr(bc));
		p3=sqr(ad*bc)*(+sqr(ab)+sqr(ac)-sqr(ad)+sqr(cd)+sqr(bd)-sqr(bc));
		p=sqr(ab*ac*bc)+sqr(ab*ad*bd)+sqr(ac*ad*cd)+sqr(cd*bd*bc);
		printf("%.4lf\n",sqrt(p1+p2+p3-p)/12);
	}
	return 0;
}