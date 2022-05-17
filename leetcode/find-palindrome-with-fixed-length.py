class Solution:
    def kthPalindrome(self, q: List[int], l: int) -> List[int]:
        b = (l + 1) // 2
        z = []
        for i in q:
            i = i + 10 ** (b - 1) - 1
            if i >= 10 ** b:
                z.append(-1)
            elif l % 2 == 0:
                z.append(int(str(i) + str(i)[::-1]))
            else:
                z.append(int(str(i)[:-1] + str(i)[::-1]))
        return z