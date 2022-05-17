class Solution:
    def constructArray(self, n: int, k: int) -> List[int]:
        a = []
        for i in range(k + 1):
            if i & 1:
                a.append(1 + i // 2)
            else:
                a.append(k + 1 - i // 2)
        a = a[::-1]
        for i in range(k + 2, n + 1):
            a.append(i)
        return a