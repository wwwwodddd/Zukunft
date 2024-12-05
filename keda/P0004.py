import sys
sys.stdin = open('sort.in', 'r')
sys.stdout = open('sort.out', 'w')
n = input()
print(*sorted(map(int, input().split())))