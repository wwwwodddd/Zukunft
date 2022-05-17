class Solution:
    def maximumPopulation(self, logs: List[List[int]]) -> int:
        a = [0 for i in range(2333)]
        for x, y in logs:
            for j in range(x, y):
                a[j] += 1
        return a.index(max(a))