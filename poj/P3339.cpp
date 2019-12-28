#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct P
{
char s[30],p;
int y,u,r;
}P;
P p[30]={0};
int d,m,s,i,j,x,y,z,cn,cy;
int cmp(const void *a,const void *b)
{
	if(((P*)a)->p!=((P*)b)->p)
		return ((P*)a)->p-((P*)b)->p;
	return ((P*)a)->r-((P*)b)->r;
}
int main()
{
	while(1)
	{
		scanf("%d",&x);
		if(x==0)
			break;
		p[0].r=x;
		scanf("%s %c",p[0].s,&p[0].p);
		scanf("%d-%d",&y,&z);
		p[0].y=z-y+1;
		while(1)
		{
			scanf("%d",&y);
			if(y<100)
				break;
			scanf("-%d",&z);
			p[0].y+=z-y+1;
		}
		p[0].u=0;
		for(i=1;i<22;i++)
		{
			p[i].r=y;
			scanf("%s %c %d-%d",p[i].s,&p[i].p,&y,&z);
			p[i].y=z-y+1;
			while(1)
			{
				scanf("%d",&y);
				if(y<100)
					break;
				scanf("-%d",&z);
				p[i].y+=z-y+1;
			}
			p[i].u=0;
		}
		d=y;
		scanf("-%d-%d",&m,&s);
		qsort(p,22,sizeof(P),cmp);
		for(i=j=x=y=z=0;i<22;i++)
			if(p[i].p=='D'&&(++x)<=d)
				p[i].u=1;
			else if(p[i].p=='M'&&(++y)<=m)
				p[i].u=1;
			else if(p[i].p=='S'&&(++z)<=s)
				p[i].u=1;
			else if(p[i].p=='G'&&(++j)==1)
				p[i].u=1;
		if(x<d||y<m||z<s||j<1||d+m+s!=10)
		{
			printf("IMPOSSIBLE TO ARRANGE\n\n");
			continue;
		}
		cy=0;
		for(i=0;i<22;i++)
			if(p[i].u==1&&(p[i].y>cy||p[i].y==cy&&p[i].r>cn))
			{
				cn=p[i].r;
				cy=p[i].y;
				x=i;
			}
		printf("%d %s %c\n",cn,p[x].s,p[x].p);
		if(p[x].p!='G')
			for(i=0;i<22;i++)
				if(p[i].u==1&&p[i].p=='G')
				{
					printf("%d %s %c\n",p[i].r,p[i].s,p[i].p);
					p[i].u=0;
				}
		for(i=0;i<22;i++)
			if(i!=x&&p[i].u==1)
				printf("%d %s %c\n",p[i].r,p[i].s,p[i].p);
		printf("\n");
	}
	return 0;
}
