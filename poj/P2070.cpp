#include<stdio.h>
int main()
{
int x,y,t;
float f;
while(scanf("%f %d %d",&f,&x,&y)&&f!=0&&x!=0&&y!=0)
	{
	t=0;
	if(f<=4.5&&x>=150&&y>=200)
		{
		printf("%s ","Wide Receiver");
		t=1;	
		}	
	if(f<=6.0&&x>=300&&y>=500)
		{
		printf("%s ","Lineman");
		t=1;	
		}
	if(f<=5.0&&x>=200&&y>=300)
		{
		printf("%s ","Quarterback");
		t=1;	
		}
	if(t==0)
		printf("%s","No positions");
	printf("\n");
	}
return 0;
}