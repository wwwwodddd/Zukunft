#include <iostream>
using namespace std;
char s[10];
bool vict(char c)
{
	 if(s[0]==c&&s[1]==c&&s[2]==c||
		s[3]==c&&s[4]==c&&s[5]==c||
		s[6]==c&&s[7]==c&&s[8]==c||
		s[0]==c&&s[3]==c&&s[6]==c||
		s[1]==c&&s[4]==c&&s[7]==c||
		s[2]==c&&s[5]==c&&s[8]==c||
		s[0]==c&&s[4]==c&&s[8]==c||
		s[2]==c&&s[4]==c&&s[6]==c
		)
		return 1;
	return 0;
}
bool check()
{
	int o,x,f,i;
	o=x=f=0;
	for(i=0;i<9;i++)
		if(s[i]=='O')
			o++;
		else if(s[i]=='X')
			x++;
		else
			f++;
	if(x<o||x>o+1)
		return 0;
	if(vict('O')&&x>o)
		return 0;
	if(!f||vict('O')||vict('X'))
		return 1;
	return 0;
}

int main()
{
	while(cin>>s&&s[0]!='e')
		printf("%svalid\n",check()?"":"in");
	return 0;
}

