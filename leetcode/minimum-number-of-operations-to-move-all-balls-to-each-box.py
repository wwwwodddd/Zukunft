class Solution:
    def minOperations(self, a: str) -> List[int]:
        n = len(a)
        s = 0
        b = 0
        c = 0
        for i in range(n):
            if a[i] == '1':
                s += i
                c += 1
        z = [s]
        for i in range(n-1):
            if a[i] == '1':
                c -= 1
                b += 1
            s -= c
            s += b
            z.append(s)
        return z
            