input()
a = map(int, raw_input().split())
print max(j for j in range(32) if all(i % 2 ** j == 0 for i in a))