class Solution:
    def pivotArray(self, a: List[int], p: int) -> List[int]:
        b = []
        for i in range(len(a)):
            b.append(((a[i] > p) - (a[i] < p), i, a[i]))
        b.sort()
        return [i[2] for i in b]