class Solution:
    def nextBeautifulNumber(self, n: int) -> int:
        def F(n):
            c = [0] * 10
            while n:
                c[n % 10] += 1
                n //= 10
            for i in range(10):
                if c[i] != 0 and c[i] != i:
                    return False
            return True
        n+=1
        while not F(n):
            n+=1
        return n