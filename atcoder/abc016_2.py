a,b,c=map(int,input().split())
print('!-+?'[(a+b==c)*2+(a-b==c)])