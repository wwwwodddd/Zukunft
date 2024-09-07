n = int(input())
s = input()
t = input()
print(sum(s[i] == t[i] == 'C' for i in range(n)))