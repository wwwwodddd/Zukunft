class Solution:
    def topKFrequent(self, a: List[int], k: int) -> List[int]:
        c=Counter(a).most_common(k)
        return[x for x,y in c]