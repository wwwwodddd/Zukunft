class Solution:
    def topKFrequent(self, w: List[str], k: int) -> List[str]:
        c=sorted(Counter(w).items(),key=lambda x:(-x[1],x[0]))[:k]
        return[x for x,y in c]
        