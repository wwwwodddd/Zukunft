#include<iostream>
using namespace std;
int isLeapYear(int x,int u)
{
	if (u>2&&(x%4==0)&&(x%100||x%400==0))
		return 1;
	return 0;
}
int a[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int t,k=0;;
int o,p,q,v,w,u;
int d1,d2,dd;
int i,j;
int main()
{
	for(i=1;i<=12;i++)
		a[i]+=a[i-1];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d/%d/%d %d/%d",&o,&p,&q,&v,&w);
		if(o==v||o+1==v||o-1==v)
		{
			u=q;
			d1=a[o-1]+p+isLeapYear(q,o);
			d2=a[v-1]+w+isLeapYear(u,v);
			dd=d2-d1;
		}
		else if(o==12&&v==1)
		{
			u=q+1;
			dd=31+w-p;
		}
		else if(o==1&&v==12)
		{
			u=q-1;
			dd=w-31-p;
		}
		else
		{
			printf("%d OUT OF RANGE\n",++k);
			continue;
		}
		if(dd==0)
			printf("%d SAME DAY\n",++k);
		else if(dd<-7||dd>7)
			printf("%d OUT OF RANGE\n",++k);
		else
		{
			printf("%d %d/%d/%d IS ",++k,v,w,u);
			if(dd<0)
				printf("%d DAY%s PRIOR\n",-dd,-dd==1?"":"S");
			else
				printf("%d DAY%s AFTER\n",dd,dd==1?"":"S");
		}
	}
	return 0;
}
