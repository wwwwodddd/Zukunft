#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<assert.h>
#define fr(i,n) for(int i=0;i<n;i++)
#define fe(i,n) for(auto i=n.begin();i!=n.end();i++)
using namespace std;
//1 dragon
// 在一次在它主动进攻的战斗结束后，如果还没有战死，就会欢呼。
//2 ninja
// 挨打了也从不反击敌人。
//3 iceman
// 每前进两步，在第2步完成的时候，生命值会减少9，攻击力会增加20。但是若生命值减9后会小于等于0，
//则生命值不减9,而是变为1。即iceman不会因走多了而死。
//4 lion
// 若是战死，则其战斗前的生命值就会转移到对手身上。
//5 wolf
// 通过主动攻击杀死敌人的次数达到偶数的时刻（次数从1开始算），在战斗完成后，该 wolf 生命值和攻击力都增加1倍。
//如果其杀死的敌人是lion,则攻击力和生命值先加倍，然后才吸取lion的生命值。获取总部的生命元奖励，发生在加倍之后。
//只有在主动攻击杀死敌人时才能有加倍的事情，反击杀死敌人则不不会发生加倍。
int rbo[5]={2,3,4,1,0};
int rbc;
int bbo[5]={3,0,1,2,4};
int bbc;
int rhp;
int bhp;
int nct;
int tmx;
int shp[5];
int sat[5];
char nam[5][20]={"dragon","ninja","iceman","lion","wolf"};
struct sdr
{
	int hp,at,ns,pos;
	sdr(int nt)
	{
		hp=shp[nt];
		at=sat[nt];
		ns=nt;
	}
};
vector<sdr>rls,bls;
int csc,ttt;
int hrs,mns;
int flg[50];
int main()
{
	scanf("%d",&csc);
	while(csc--)
	{
		printf("Case:%d\n",++ttt);
		scanf("%d %d %d",&rhp,&nct,&tmx);
		bhp=rhp;
		fr(i,5)
			scanf("%d",shp+i);
		fr(i,5)
			scanf("%d",sat+i);
		for(hrs=0;hrs<=tmx;hrs++)
		{
			if(rhp>=shp[rbo[rbc%5]])
			{
				int nt=rbo[rbc%5];
				printf("%03d:00 red %s %d born",nam[nt],rbc);
				rls.push_back(sdr(nt));
				rbc++;
			}
			if(bhp>=shp[bbo[bbc%5]])
			{
				int nt=bbo[bbc%5];
				printf("%03d:00 blue %s %d born",nam[bbo[bbc%5]],bbc);
				bls.push_back(sdr(nt));
				bbc++;
			}
		}
		fe(i,rls)
		{
			
		}
		fe(i,bls)
		end:
	}
	return 0;
}