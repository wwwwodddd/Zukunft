#include<stdio.h>
#include<string.h>
char s[15];
int i,j,k,u,z;
int main()
{
	while(scanf("%s",s)+1)
	{
		i=10,u=j=0;
		for(k=0;s[k];k++)
			if(s[k]>='0'&&s[k]<='9')
				u+=(s[k]-'0')*i--;
			else if(s[k]=='?')
				z=i--;
			else
				u+=i*10;
		for(j=0;j<=9;j++)
			if((u+j*z)%11==0)
			{
				printf("%d\n",j);
				break;
			}
		if(j==10&&z==1)
			if((u+j*z)%11==0)
				printf("%c\n",'X');
			else
				printf("%d\n",-1);
		if(j==10&&z!=1)
			printf("%d\n",-1);
	}
	return 0;
}
