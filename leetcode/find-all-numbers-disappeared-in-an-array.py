class Solution:
    def findDisappearedNumbers(self, a: List[int]) -> List[int]:
        for i in range(len(a)):
            while a[a[i] - 1] != a[i]:
                a[a[i] - 1], a[i] = a[i], a[a[i] - 1]
        return [i+1 for i in range(len(a)) if a[i] != i+1]