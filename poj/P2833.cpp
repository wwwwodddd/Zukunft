#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
int b,f,n,i,x;
double sum;
priority_queue<int,vector<int>,less<int> >q1;
priority_queue<int,vector<int>,greater<int> >q2;
int main()
{
	while(scanf("%d%d%d",&b,&f,&n)&&b+f+n)
	{
		sum=0;
		for (i=0;i<n;i++)
		{
			scanf("%d",&x);
			sum+=x;
			q2.push(x);
			q1.push(x);
			if(q1.size()>f)
				q1.pop();
			if(q2.size()>b)
				q2.pop();
		}
		while(!q1.empty())
		{
			sum-=q1.top();
			q1.pop();
		}
		while(!q2.empty())
		{
			sum-=q2.top();
			q2.pop();
		}
		printf("%.6lf\n",sum/(n-b-f));
	}
	return 0;
}

