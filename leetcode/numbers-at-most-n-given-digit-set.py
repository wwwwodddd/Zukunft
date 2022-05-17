class Solution:
    def atMostNGivenDigitSet(self, s: List[str], n: int) -> int:
        s = set(map(int, s))
        a = []
        n += 1
        while n:
            a.append(n % 10)
            n //= 10
        z = 0
        for i in range(1, len(a)):
            z += len(s) ** i
        for i in range(len(a))[::-1]:
            for j in s:
                if j < a[i]:
                    z += len(s) ** i
            if a[i] not in s:
                break
        return z