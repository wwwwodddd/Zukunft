#R=lambda:[*map(int,input().split())];exec(R()[0]*'R();a=R();b=R();print(sum(max(x-min(a),y-min(b))for x,y in zip(a,b)));')

I=lambda:*map(int,input().split())
for i in range(I()[0]):I();a=I();b=I();print(sum(max(x-min(a),y-min(b))for x,y in zip(a,b)))
