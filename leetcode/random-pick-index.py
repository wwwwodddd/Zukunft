class Solution:
    g = {}
    def __init__(self, a: List[int]):
        self.g = {}
        for i in range(len(a)):
            if a[i] not in self.g:
                self.g[a[i]] = []
            self.g[a[i]].append(i)

    def pick(self, target: int) -> int:
        if target not in self.g:
            return None
        else:
            return random.choice(self.g[target])
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)