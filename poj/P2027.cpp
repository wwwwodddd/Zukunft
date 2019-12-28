#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int i;
	int n,x,y;
	cin >> n;
	for(i=0;i<n;i++)
	{
		cin >> x >> y;
		if(x<y)
			cout << "NO BRAINS" <<endl;
		else
			cout << "MMM BRAINS" <<endl;
	}
	return 0;
}