#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;
int csc;
int t1,t2,t3;
int ta,tb;
int main()
{
	while(1)
	{
		printf("%d::\n",++csc);
		system("bzoj2459mk.exe");
		t1=clock();
		system("bzoj2459.exe");
		t2=clock();
		system("c.exe");
		t3=clock();
		printf("time :: %d vs %d\n",t2-t1,t3-t2);
		if(system("fc c.out s.out"))
		{
			puts("error");
			system("pause");
			return 0;
		}
	}
	return 0;
}
