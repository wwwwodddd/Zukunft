class Solution:
    def findSmallestSetOfVertices(self, n: int, e: List[List[int]]) -> List[int]:
        d=[0 for i in range(n)]
        for x,y in e:
            d[y]+=1
        return [i for i in range(n)if d[i]==0]