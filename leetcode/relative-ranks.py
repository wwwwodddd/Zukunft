class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        p = list(range(len(score)))
        p.sort(key=lambda x:-score[x])
        r = [0] * len(score)
        for i in range(len(p)):
            if i < 3:
                r[p[i]] = ["Gold Medal","Silver Medal","Bronze Medal"][i]
            else:
                r[p[i]] = str(i + 1)
        return r