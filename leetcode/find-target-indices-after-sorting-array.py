class Solution:
    def targetIndices(self, a: List[int], x: int) -> List[int]:
        a.sort()
        return [i for i in range(len(a))if a[i]==x]