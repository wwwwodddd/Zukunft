#include<iostream>
#include<math.h>
using namespace std;
int i,u,v;
double x[6],y[6];
int s[100]={100,100,100,80,80,80,60,60,60,40,40,40,20,20,20};
int R(double x, double y)
{
	double dis=sqrt(x*x + y*y);
	return s[(int)(dis-0.00000001)];
}
int main()
{
	while(1)
	{
		for(i=0;i<6;i++)
			scanf("%lf%lf", &x[i], &y[i]);
		if(x[0]==-100)
			break;
		u=v=0;
		for(i=0;i<3;i++)
			u+=R(x[i],y[i]);
		for(i=3;i<6;i++)
			v+=R(x[i],y[i]);
		printf("SCORE: %d to %d,",u,v);
		if(u>v)
			printf(" PLAYER 1 WINS.\n");
		else if(u<v)
			printf(" PLAYER 2 WINS.\n");
		else
			printf(" TIE.\n");
	}
	return 0;
}