#include<stdio.h>
int s[256],l;
char k,lk;
char z[1000];
void put(char x)
{
	z[l++]=x;
}
int main()
{
	lk=' ';
	s['A']=s['E']=s['I']=s['O']=s['U']=1;
	while((k=getchar())!=EOF)
	{
		if(s[k]&&k>='A'&&k<='Z')
			continue;
		s[k]=1;
		if(lk==' '&&k==' ')
			continue;
		if(!(k>='A'&&k<='Z')&&k!=' ')
			while(z[l-1]==' ')
				l--;
		put(k);
		lk=k;
	}
	puts(z);
	return 0;
}