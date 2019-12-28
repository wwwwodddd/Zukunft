#include<stdio.h>
int s(int x,int y)
{
	int ans=0;
	while(x)
	{
		ans+=x%y;
		x/=y;
	}
	return ans;
}
int main()
{
	for(int i=2992;i<10000;i++)
		if(s(i,16)==s(i,10)&&s(i,16)==s(i,12))
			printf("%d\n",i);
	return 0;
}