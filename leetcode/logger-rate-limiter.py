class Logger:

    def __init__(self):
        self.g = {}

    def shouldPrintMessage(self, t: int, s: str) -> bool:
        if s not in self.g or t >= self.g[s] + 10:
            self.g[s] = t
            return True
        return False


# Your Logger object will be instantiated and called as such:
# obj = Logger()
# param_1 = obj.shouldPrintMessage(timestamp,message)