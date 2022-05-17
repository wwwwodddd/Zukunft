class Solution:
    def nextGreaterElement(self, a: List[int], b: List[int]) -> List[int]:
        z = {}
        s = []
        for i in b:
            while len(s) and s[-1] < i:
                z[s.pop()] = i
            s.append(i)
        return [z.get(i, -1) for i in a]