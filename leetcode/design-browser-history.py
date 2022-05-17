class BrowserHistory:

    def __init__(self, homepage: str):
        self.a = [homepage]
        self.i = 0

    def visit(self, url: str) -> None:
        self.a = self.a[:self.i+1]
        self.a.append(url)
        self.i += 1

    def back(self, steps: int) -> str:
        self.i = max(self.i - steps, 0)
        return self.a[self.i]
    
    def forward(self, steps: int) -> str:
        self.i = min(self.i + steps, len(self.a) - 1)
        return self.a[self.i]


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)