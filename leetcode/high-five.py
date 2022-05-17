class Solution:
    def highFive(self, a: List[List[int]]) -> List[List[int]]:
        b = defaultdict(list)
        for x, y in a:
            b[x].append(y)
        for x in b:
            b[x].sort()
            b[x] = sum(b[x][-5:]) // 5
        return sorted(b.items())