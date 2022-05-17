class Solution:
    def distanceBetweenBusStops(self, a: List[int], s: int, t: int) -> int:
        if s>t:
            s,t=t,s
        return min(sum(a[s:t]), sum(a) - sum(a[s:t]))