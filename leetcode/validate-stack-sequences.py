class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        s = [-1]
        while len(popped):
            while len(pushed) and s[-1] != popped[0]:
                s.append(pushed.pop(0))
            if s.pop() != popped.pop(0):
                return False
        return True
                