class Solution:
    def smallestNumber(self, n: int) -> int:
        if n == 0:
            return 0
        if n < 0:
            n = -n
            n = sorted(list(str(n)),reverse=True)
            n = int(''.join(n))
            return -n
        else:
            n = sorted(list(str(n)))
            for i in range(len(n)):
                if n[i] != '0':
                    n[0], n[i] = n[i], n[0]
                    break
            n = int(''.join(n))
            return n