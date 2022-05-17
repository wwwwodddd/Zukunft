class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        z = ''
        for i in range(n)[::-1]:
            c = 0
            while k > 2 ** i:
                k -= 2 ** i
                c += 1
            if i == n - 1:
                if c >= 3:
                    return ''
                z += 'abc'[c]
            else:
                if c >= 2:
                    return ''
                z += [i for i in 'abc' if i != z[-1]][c]
        return z
