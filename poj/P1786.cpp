#include <iostream>
using namespace std;
struct C{char x,y;};
struct P{C c[13];}p[4];
char dir[4][6]={"South","West","North","East"};
int cmp2(char a,char b)
{
	char r[]="23456789TJQKA";
	int ra=0,rb=0;
	while(r[ra]!=a)
		ra++;
	while(r[rb]!=b)
		rb++;
	return ra-rb;
}
int cmp1(char a,char b)
{
	char s[]="CDSH";
	int sa=0,sb=0;
	while(s[sa]!=a)
		sa++;
	while(s[sb]!=b)
		sb++;
	return sa - sb;
}
int cmp(const void *a,const void *b)
{
	struct C *c=(C *)a;
	struct C *d=(C *)b;
	if(c->x == d->x)
		return cmp2(c->y, d->y);
	else
		return cmp1(c->x, d->x);
}
void show(int n)
{
	int i;
	printf("%s player:\n", dir[n]);
	printf("+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
	for(i=0;i<13;i++)
		printf("|%c %c",p[n].c[i].y,p[n].c[i].y);
	printf("|\n");
	for(i=0;i<13;i++)
		printf("| %c ",p[n].c[i].x);
	printf("|\n");
	for(i=0;i<13;i++)
		printf("|%c %c",p[n].c[i].y,p[n].c[i].y);
	printf("|\n");
	printf("+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
}
int main()
{
	int z,i,j;
	char s;
	while(cin>>s&&s!='#')
	{
		z=0;
		while(dir[z][0]!=s)
			z++;
		for(i=0;i<52;i++)
			cin>>p[(i+z+1)%4].c[i/4].x>>p[(i+z+1)%4].c[i/4].y;
		for(i=0;i<4;i++)
		{
			qsort(p[i].c,13,sizeof(p[i].c[0]),cmp);
			show(i);
		}
		cout<<endl;
	}
}
