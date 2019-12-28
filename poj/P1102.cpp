#include<stdio.h>
#include<string.h>
int l;
int k;
char c[100][300],s[20];
void A(int x,int y)
{
	for(int i=0;i<k;i++)
		c[x][y+i]='-';
}
void B(int x,int y)
{
	for(int i=0;i<k;i++)
		c[x+i][y]='|';
}
void w1(int z)
{
	B(1,z+k+1);
	B(k+2,z+k+1);
}
void w2(int z)
{
	A(0,z+1);
	A(k+1,z+1);
	A(2*k+2,z+1);
	B(1,z+k+1);
	B(k+2,z);
}
void w3(int z)
{
	A(0,z+1);
	A(k+1,z+1);
	A(2*k+2,z+1);
	B(1,z+k+1);
	B(k+2,z+k+1);
}
void w4(int z)
{
	A(k+1,z+1);
	B(1,z);
	B(1,z+k+1);
	B(k+2,z+k+1);
}
void w5(int z)
{
	A(0,z+1);
	A(k+1,z+1);
	A(2*k+2,z+1);
	B(1,z);
	B(k+2,z+k+1);
}
void w6(int z)
{
	A(0,z+1);
	A(k+1,z+1);
	A(2*k+2,z+1);
	B(1,z);
	B(k+2,z);
	B(k+2,z+k+1);
}
void w7(int z)
{
	A(0,z+1);
	B(1,z+k+1);
	B(k+2,z+k+1);
}
void w8(int z)
{
	A(0,z+1);
	A(k+1,z+1);
	A(2*k+2,z+1);
	B(1,z);
	B(1,z+k+1);
	B(k+2,z);
	B(k+2,z+k+1);
}
void w9(int z)
{
	A(0,z+1);
	A(k+1,z+1);
	A(2*k+2,z+1);
	B(1,z);
	B(1,z+k+1);
	B(k+2,z+k+1);
}
void w0(int z)
{
	A(0,z+1);
	A(2*k+2,z+1);
	B(1,z);
	B(1,z+k+1);
	B(k+2,z);
	B(k+2,z+k+1);
}
void print()
{
	for(int i=0;i<2*k+3;i++)
	{
		for(int j=0;j<l*(k+3);j++)
			printf("%c",c[i][j]);
		printf("\n");
	}
}
int main()
{
	while(scanf("%d %s",&k,s)&&(k||s[0]-'0'))
	{
		memset(c,' ',sizeof(c));
		l=strlen(s);
		for(int i=0;i<l;i++)
			if(s[i]-'0'==0)
				w0(i*(k+3));
			else if(s[i]-'0'==1)
				w1(i*(k+3));
			else if(s[i]-'0'==2)
				w2(i*(k+3));
			else if(s[i]-'0'==3)
				w3(i*(k+3));
			else if(s[i]-'0'==4)
				w4(i*(k+3));
			else if(s[i]-'0'==5)
				w5(i*(k+3));
			else if(s[i]-'0'==6)
				w6(i*(k+3));
			else if(s[i]-'0'==7)
				w7(i*(k+3));
			else if(s[i]-'0'==8)
				w8(i*(k+3));
			else if(s[i]-'0'==9)
				w9(i*(k+3));
		print();
		printf("\n");
	}
	return 0;
}