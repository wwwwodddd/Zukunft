class Solution:
    def findDuplicates(self, a: List[int]) -> List[int]:
        for i in range(len(a)):
            while True:
                t = a[i] - 1
                a[i], a[t] = a[t], a[i]
                if a[i] == a[t]:
                    break
        z = []
        for i in range(len(a)):
            if a[i] != i + 1:
                z.append(a[i])
        return z