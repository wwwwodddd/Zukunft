#include<iostream>
#include<string.h>
#define F(x) for(x=0;x<n;x++)
#define P(x) printf("%d channel%s needed.\n",x,x==1?"":"s");
int n;
char map[30][30];
void init()
{
	memset(map,0,sizeof(map));
	int i,j;
	char s[30];
	F(i)
    {
    	scanf("%s",s);
    	for(j=strlen(s)-1;j>1;j--)
    	  	  map[s[0]-'A'][s[j]-'A']=map[s[j]-'A'][s[0]-'A']=1;
	}
	return;
}
void solve()
{
	int i,j,k,l;
	F(i)
		F(j)
			if(map[i][j])
				F(k)
					if(map[i][k]&&map[j][k])
						F(l)
							if(map[i][l]&&map[j][l]&&map[k][l])
							{
								P(4);
								return;
							}
	F(i)
		F(j)
			if(map[i][j])
				F(k)
					if(map[i][k]&&map[j][k])
					{
						P(3);
						return;
					}
	F(i)
		F(j)
			if(map[i][j])
			{
				P(2);
				return;
			}
	P(1);
	return;
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
	init();
	solve();
	}
}