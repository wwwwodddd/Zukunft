class Solution:
    def findingUsersActiveMinutes(self, a: List[List[int]], k: int) -> List[int]:
        s=defaultdict(set)
        for x,y in a:
            s[x].add(y)
        c=[0]*k
        for i in s:
            c[len(s[i])-1]+=1
        return c