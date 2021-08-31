import itertools
s,n=input().split()
print(''.join(sorted(set(itertools.permutations(s)))[int(n)-1]))