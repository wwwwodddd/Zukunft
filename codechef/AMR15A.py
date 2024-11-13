n = int(input())
s = sum(int(i) % 2 for i in input().split())
print(['NOT READY', 'READY FOR BATTLE'][s * 2 < n])
