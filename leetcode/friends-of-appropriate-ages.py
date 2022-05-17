class Solution:
    def numFriendRequests(self, a: List[int]) -> int:
        c = Counter(a)
        z = 0
        for x in c:
            for y in c:
                if 2 * y <= x + 14 or y > x or y > 100 and x < 100:
                    pass
                else:
                    if x == y:
                        z += c[x] * (c[y] - 1)
                    else:
                        z += c[x] * c[y]
        return z