#include<stdio.h>
#include<iostream>
#include<queue>
#include<math.h>
using namespace std;
int n;
double a,b,c;
priority_queue<double>que;
int main()
{
	cin >> n;
	while(n--)
	{
		cin >> a;
		que.push(a);
	}
	while(que.size()!=1)
	{
	a=que.top();
	que.pop();
	b=que.top();
	que.pop();
	que.push(2*sqrt(a*b));
	}
	printf("%.3lf",que.top());
	return 0;
}
