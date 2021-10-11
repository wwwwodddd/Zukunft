import itertools
print(sorted(list(set(sum(a)for a in itertools.combinations(map(int,input().split()),3))))[-3])