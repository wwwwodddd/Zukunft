class Solution:
    def maximumNumberOfOnes(self, n: int, m: int, s: int, o: int) -> int:
        a = []
        for i, ic in [(n // s, s - n % s), (n // s + 1, n % s)]:
            for j, jc in [(m // s, s - m % s), (m // s + 1, m % s)]:
                a.append((i * j, ic * jc))
        a.sort(reverse=True)
        z = 0
        for x, y in a:
            t = min(o, y)
            z += t * x
            o -= t
        return z