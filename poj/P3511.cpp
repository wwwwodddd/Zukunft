#include<iostream>
using namespace std;
int a[1000020]; 
int b[1000020]; 
bool c[1000020]; 
int p[200020];
int l1,l2,l;
void slove()
{
	for(int i=2;i<=1000000;i++)
	{
		if(!c[i])
		{
			p[l++]=i;
			l1++;
			if(i%4==1||i==2)
				l2++;
		}
		a[i]=l1;
		b[i]=l2;
		for(int j=0;j<l&&p[j]*i<=1000000;j++)
		{
			c[p[j]*i]=1;
			if(i%p[j]==0)
				break;
		}
	}
}
int main()
{
	int u,v,x,y;
	slove();
	while(scanf("%d%d",&u,&v)&&(u!=-1||v!=-1))
	{
		x=max(u,1);
		y=max(v,0);
		printf("%d %d %d %d\n",u,v,a[y]-a[x-1],b[y]-b[x-1]);
	}
	return 0;
}
