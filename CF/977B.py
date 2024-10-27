import collections
n = input()
s = input()
c = collections.Counter(s[i - 2: i] for i in range(2, len(s) + 1))
print(c.most_common(1)[0][0])