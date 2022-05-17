class Solution:
    def findContestMatch(self, n: int) -> str:
        def gan(x, d):
            if (1 << d) == 2 * n:
                return x
            return '(%s,%s)' % (gan(x, d + 1), gan((1 << d) + 1 - x, d + 1))
        return gan(1, 1)