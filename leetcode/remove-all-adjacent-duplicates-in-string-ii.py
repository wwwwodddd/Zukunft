class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        a = [['~', 0]]
        for i in s:
            if i == a[-1][0]:
                a[-1][1] += 1
                if a[-1][1] == k:
                    a.pop()
            else:
                a.append([i, 1])
        return ''.join(x * y for x, y in a)