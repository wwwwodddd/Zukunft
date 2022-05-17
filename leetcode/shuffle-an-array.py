class Solution:

    def __init__(self, a: List[int]):
        self.a = a

    def reset(self) -> List[int]:
        return self.a

    def shuffle(self) -> List[int]:
        b = self.a.copy()
        shuffle(b)
        return b

# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()