class Solution:
    def reorganizeString(self, s: str) -> str:
        c = Counter(s).most_common()
        if c[0][1] > (len(s) + 1) // 2:
            return ''
        t = ''.join(x * y for x, y in c)
        return ''.join(t[i // 2 + i % 2 * (len(s) + 1) // 2] for i in range(len(s)))