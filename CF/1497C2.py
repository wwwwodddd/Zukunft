for s in[*open(0)][1:]:
	n,k=map(int,s.split())
	n-=k-3
	print(*[[n>>1,n>>2,n>>2],[n-1>>1,n-1>>1,n&-n]][n&3>0],*([1]*(k-3)))
