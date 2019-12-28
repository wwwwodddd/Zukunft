#include<stdio.h>
#define lim 131072
struct N{int l,r,sa,w,rv;}t[524288];
int a[131080];
void bd(int p,int l,int r)
{
	t[p].l=l;
	t[p].r=r;
	t[p].sa=0;
	t[p].w=0;
	t[p].rv=0;
	if(l==r)
		return;
	bd(p*2,l,(l+r)/2);
	bd(p*2+1,(l+r)/2+1,r);
}
void rev(int p)
{
	t[p].w^=1;
	if(t[p].sa!=-1)
		t[p].sa^=1;
	else
		t[p].rv^=1;
}
void same(int p,int x)
{
	t[p].w=x;
	t[p].sa=x;
	t[p].rv=0;
}
void pd(int p)
{
	if(t[p].l==t[p].r)
		return;
	if(t[p].sa!=-1)
	{
		t[2*p].sa=t[p].sa;
		t[2*p+1].sa=t[p].sa;
		t[p].sa=-1;
		t[2*p].rv=t[2*p+1].rv=t[p].rv=0;
	}
	if(t[p].rv)
	{
		if(t[2*p].rv)
			t[2*p].rv=0;
		else if(t[2*p].sa!=-1)
			t[2*p].sa^=1;
		else
			t[2*p].rv=1;
		if(t[2*p+1].rv)
			t[2*p+1].rv=0;
		else if(t[2*p+1].sa!=-1)
			t[2*p+1].sa^=1;
		else
			t[2*p+1].rv=1;
		t[p].rv=0;
	}
}
void ud(int p,int l,int r,int x)
{
	pd(p);
	if(t[p].l>=l&&t[p].r<=r)
	{
		same(p,x);
		return;
	}
	if(t[p].r<l||t[p].l>r)
		return;
	ud(p*2,l,r,x);
	ud(p*2+1,l,r,x);
	return;
}
void reverse(int p,int l,int r)
{
	pd(p);
	if(t[p].l>=l&&t[p].r<=r)
	{
		rev(p);
		return;
	}
	if(t[p].r<l||t[p].l>r)
		return;
	reverse(p*2,l,r);
	reverse(p*2+1,l,r);
	return;
}
void dfs(int p)
{
	if(t[p].l==t[p].r)
	{
		a[t[p].l]=t[p].sa;
		return;
	}
	pd(p);
	dfs(p*2);
	dfs(p*2+1);
}
int main ()
{
	char op,ch1,ch2;
	int l,r,i;
	bd(1,0,lim);
	while(scanf("%c %c%d,%d%c",&op,&ch1,&l,&r,&ch2)+1)
	{
		getchar();
		l=l+l;
		r=r+r;
		if(ch1=='(')
			l++;
		if(ch2==')')
		r--;
		if(l>r)
			continue;
		switch(op)
		{
			case 'U':
				ud(1,l,r,1);
			break;
			case 'I':
				if(l>0)
					ud(1,0,l-1,0);
				if(r<lim)
					ud(1,r+1,lim,0);
			break;
			case 'D':
				ud(1,l,r,0);
			break;
			case 'C':
				if(l>0)
					ud(1,0,l-1,0);
				if(r<lim)
					ud(1,r+1,lim,0);
				reverse(1,l,r);
			break;
			case 'S':
				reverse(1,l,r);
			break;
		}
		dfs(1);
		for(i=0;i<32;i++)
			printf("%d ",a[i]);
		puts("");
	}
	dfs(1);
	int s,e,u=1;
	for(i=0;i<=lim;i++)
	{
		while(i<=lim&&!a[i])
			i++;
		s=i;
		if(i>lim)
			break;
		while(i<=lim&&a[i])
			i++;
		e=i-1;
		u=0;
		if(s&1)
			printf("(%d,",s/2);
		else
			printf("[%d,",s/2);
		if(e&1)
			printf("%d) ",(e+1)/2);
		else
			printf("%d] ",e/2);
	}
	if(u)
		printf("empty set");
	printf("\n");
	return 0;
}