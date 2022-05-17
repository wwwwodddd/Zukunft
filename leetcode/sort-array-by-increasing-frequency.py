class Solution:
    def frequencySort(self, a: List[int]) -> List[int]:
        c=Counter(a)
        return sorted(a,key=lambda x:(c[x],-x))