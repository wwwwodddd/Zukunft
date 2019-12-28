/*
以前只是做过求LCA(最大公共子序列)的大小,但是如果要求所有的LCA串,且不允许重复的,这就犯难了.想了
n久尝试了n种办法都WA.最后只能去网上看看前辈们的解题报告了,可是这一题解题报告一直没有找到,难怪
这题AC的人这么少.搜了n久最后找到了李博CEOI 2003的解题报告，看了之后才恍然大悟.不过这也不是那么
容易能想出来的.
(1)首先分别计算两个输入串的loc[i][j].str1 的loc[i][j]表示在str1中位于位置i以及它之前的且距离i最
近的字母j的位置,则可以得到
loc[i][j] = i当 str[i] == j;
            loc[i - 1][j]当 str[i] != j
(2)首先需要对输入串计算一变LCA,即LCA[i][j]表示两个串str1[1...i]与str2[1...j]的LCA的长度
 LCA[i][j] = LCA[i - 1][j - 1], 当 str1[i] == str2[j];
             max(LCA[i - 1][j], LCA[i][j - 1]), 当 str1[i] != str2[j]
(2)然后从两个串的末尾递推,假设当前处理到两个串的位置分别为n,m
 那么
 (1)如果str1[n] == str2[m],则将当前字符str1[n]加入结果字符串res,同时n,m的位置分别向前推进1变为n - 1, m - 1
 (2)如果str1[n] != str2[m],则遍历所有的26个字母，找到LCA[loc1[n][k], loc2[m][k]]最大的那些k的位置，
    并向前推进，将n, m分别更新为loc1[n][k], loc2[m][k]
通过这一题对LCA的认识更加深了一步,继续学习ing
*/
#include <iostream>
#include <string>
#include <algorithm>
#define MAX_N 10005
#define MAX_LEN 100
#define maxv(a, b) ((a) >= (b) ? (a) : (b))
using namespace std;
struct str
{
    string seq;
}strs[MAX_N + 1];
int n, maxLen;
string str1, str2;
int len1, len2;
int lcs[MAX_LEN + 1][MAX_LEN + 1];
int loc1[MAX_LEN + 1][27];
int loc2[MAX_LEN + 1][27];
//计算loc
void getLoc(string str, int loc[][27])
{
    int i, j, len = str.length();
    memset(loc, 0, sizeof(loc));
    for(i = 1; i <= len; i++) 
    {
        for(j = 1; j <= 26; j++)
        {
            if(str[i - 1] - 'a' + 1 == j)
                loc[i][j] = i;
            else
            {
                if(loc[i - 1][j] == 0) continue;
                loc[i][j] = loc[i - 1][j];
            }
        }
    }
}
//计算LCS
void getLCS()
{
    int i, j;
    memset(lcs, 0xbf, sizeof(lcs));
    for(i = 0; i <= maxv(len1, len2); i++) lcs[i][0] = lcs[0][i] = 0;
    for(i = 1; i <= len1; i++)
    {
        for(j = 1; j <= len2; j++)
        {
            if(str1[i - 1] == str2[j - 1]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
            {
                if(lcs[i - 1][j] > lcs[i][j - 1]) lcs[i][j] = lcs[i - 1][j];
                else if(lcs[i - 1][j] < lcs[i][j - 1]) lcs[i][j] = lcs[i][j - 1];
                else lcs[i][j] = lcs[i][j - 1];
            }
        }
    }
}
//逆向处理
void solve(int p1, int p2, string res)
{
    //处理到头了则需要将当前的res加入结果字符串数组
    if(p1 == -1 || p2 == -1)
    {
        strs[n++].seq = res;
        return;
    }
    //当当前位置的两个字符相同时,将这个字符加入结果字符串,并向前推进
    if(str1[p1] == str2[p2]) 
    {
        solve(p1 - 1, p2 - 1, str1[p1] + res);
    }
    else
    {
        //否则需要找到具有最优(最大)的LCA值的前驱位置
        int maxV = INT_MIN, maxP1, maxP2, i;
        //寻找最大值maxV
        for(i = 1; i <= 26; i++)
        {
                        
            int pp1 = loc1[p1 + 1][i], pp2 = loc2[p2 + 1][i];
            //避免在当前位置发生死循环
            if(pp1 - 1 == p1 && pp2 - 1 == p2) continue;
            if(lcs[pp1][pp2] > maxV)
            {
                maxV = lcs[pp1][pp2];
                maxP1 = pp1;
                maxP2 = pp2;
            }
        }
        //从找到的那些最大值继续向前推进
        for(i = 1; i <= 26; i++)
        {
            int pp1 = loc1[p1 + 1][i], pp2 = loc2[p2 + 1][i];
            if(pp1 - 1 == p1 && pp2 - 1 == p2) continue;
            if(lcs[pp1][pp2] == maxV)
                solve(pp1 - 1, pp2 - 1, res);
        }
    }
}
bool compare(const str &s1, const str &s2)
{
    return s1.seq <= s2.seq;
}
int main()
{
    cin>>str1>>str2;
    maxLen = INT_MIN;
    n = 0;
    len1 = str1.length(); len2 = str2.length();
    string res = "";
    getLoc(str1, loc1);
    getLoc(str2, loc2);
    getLCS();
        
    solve(len1 - 1, len2 - 1, res);
    sort(strs, strs + n, compare);
    for(int i = 0; i < n; i++)
    {
        cout<<strs[i].seq<<endl;
        res = strs[i].seq;
    }
    return 0;
}

/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char a[111],b[111];
int c[111][111];
int d[111][111],xyz;
char ans[10000][111];
char s[111];
int m,n;
int cmp(const void *a,const void *b)
{
	return strcmp((char*)a,(char*)b);
}
void dfs(int x,int y,int l)
{
	int i;
	if(l<=0)
	{
		for(i=0;i<xyz;i++)
			if(strcmp(ans[i],s+1)==0)
				return;
		memcpy(ans[xyz++],s+1,c[m-1][n-1]);
		return;
	}
	if(x<0||y<0)
		return;
	if(d[x][y]==4)
	{
		s[l]=a[x];
		dfs(x-1,y-1,l-1);
		s[l]=0;
	}
	if(d[x][y]==3||d[x][y]==1)
		dfs(x-1,y,l);
	if(d[x][y]==3||d[x][y]==2)
		dfs(x,y-1,l);
	return;
}
int main()
{

	int i,j,k;
	scanf("%s %s",a,b);
	m=strlen(a);
	n=strlen(b);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			if(a[i]==b[j])
			{
				c[i][j]=c[i-1][j-1]+1;
				d[i][j]=4;
			}
			else
			{
				if(c[i-1][j]>=c[i][j-1])
				{
					c[i][j]=c[i-1][j];
					d[i][j]+=1;
				}
				if(c[i-1][j]<=c[i][j-1])
				{
					c[i][j]=c[i][j-1];
					d[i][j]+=2;
				}
			}
		}
	dfs(m-1,n-1,c[m-1][n-1]);
	qsort(ans,xyz,111,cmp);
	for(i=0;i<xyz;i++)
		if(strcmp(ans[i],ans[i+1])==0)
			continue;
		else
			printf("%s\n",ans[i]);
	printf("%d\n",xyz);
	return 0;
}*/