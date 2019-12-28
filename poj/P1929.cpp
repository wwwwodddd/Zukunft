#include<stdio.h>
#include<string.h>
int c[5]={9,4,4,4,7};
char s[10],u;
int i,j,k,l,t;
int x,sum,per,p1,c1;
double sc,ss;
int pround(float f)
{
  float eps=0.49;
  int i=(int)f;
  if((f-(float)i)<eps)
    return i;
  else 
    return i+1;
}
int main()
{
	while(1)
	{
		ss=sc=0;
		t=0;
		while(scanf("%s",s)&&s[0]!='-')
		{
			per=100;
			sum=p1=c1=0;
			l=strlen(s);
			u=s[l-1];
			s[l-1]=0;
			sscanf(s,"%d",&x);
			if(u=='%')
				per-=x;
			if(u=='C')
				sum+=x;
			if(u=='g')
				sum+=x*c[0];
			if(u=='%')
				p1=x;
			if(u=='C')
				c1=x;
			if(u=='g')
				c1=x*c[0];
			for(i=1;i<5;i++)
			{
				scanf("%s",s);
				l=strlen(s);
				u=s[l-1];
				s[l-1]=0;
				sscanf(s,"%d",&x);
				if(u=='%')
					per-=x;
				if(u=='C')
					sum+=x;
				if(u=='g')
					sum+=x*c[i];
			}
			ss+=100.0*sum/per;
			if(p1)
				sc+=1.0*p1*sum/per;
			else
				sc+=c1;
			t=1;
		}
		if(t==0)
			break;
		if(ss==0&&sc==0)
			printf("0%c\n",'%');
		else
			printf("%d%c\n",pround(sc/ss*100.0),'%');
	}
	return 0;
}