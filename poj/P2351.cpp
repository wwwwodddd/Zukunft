#include<iostream>
#include<string>
using namespace std;
int t,h,m,i,j,z;
string s,c;
string f[32]={
"UTC" ,"GMT" ,"BST" ,"IST" ,"WET" ,"WEST","CET" ,"CEST","EET" ,"EEST","MSK",
"MSD" ,"AST" ,"ADT" ,"NST" ,"NDT" ,"EST" ,"EDT" ,"CST" ,"CDT" ,"MST" ,"MDT",
"PST" ,"PDT" ,"HST" ,"AKST","AKDT","AEST","AEDT","ACST","ACDT","AWST"};
int d[32]={0,0,60,60,0,60,60,120,120,180,180,240,-240,-180,-210,-150,-300,-240,-360,-300,-420,-360,-480,-420,-600,-540,-480,600,660,570,630,480};
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		cin>>s;
		if(s[0]=='n')
			h=12,m=0;
		else if(s[0]=='m')
			h=24,m=0;
		else
		{
			sscanf(s.c_str(),"%d:%d",&h,&m);
			h%=12;
			cin>>s;
			if(s[0]=='p')
				h+=12;
		}
		i=j=0;
		cin>>s;
		while(s!=f[i])
			i++;
		cin >> s;
		while(s!=f[j])
			j++;
		z=60*h+m+d[j]-d[i];
		z+=1440;
		z%=1440;
		if(!z)
			puts("midnight");
		else if(z==720)
			puts("noon");
		else
		{
			m=z%60;
			h=z/60;
			if(!h)
				printf("12:%02d a.m.\n",m);
			else if(h < 12)
				printf("%d:%02d a.m.\n",h,m);
			else if(h == 12)
				printf("%d:%02d p.m.\n",h,m);
			else
				printf("%d:%02d p.m.\n",h-12,m);
		}
	}
	return 0;
}