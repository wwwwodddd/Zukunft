class Solution:
    def secondHighest(self, s: str) -> int:
        a = set()
        for i in s:
            if i.isdigit():
                a.add(int(i))
        a = [-1, -1] + sorted(list(a))
        return a[-2]
            