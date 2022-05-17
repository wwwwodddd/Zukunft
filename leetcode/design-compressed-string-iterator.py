class StringIterator:

    def __init__(self, s: str):
        self.s = s
        self.p = 0
        self.c = 0
        self.d = 0


    def next(self) -> str:
        if not self.hasNext():
            return ' '
        if self.d == 0:
            self.c = self.s[self.p]
            self.p += 1
            while self.p < len(self.s) and self.s[self.p].isdigit():
                self.d = self.d * 10 + int(self.s[self.p])
                self.p += 1
        self.d -= 1
        return self.c

    def hasNext(self) -> bool:
        return self.d > 0 or self.p < len(self.s)


# Your StringIterator object will be instantiated and called as such:
# obj = StringIterator(compressedString)
# param_1 = obj.next()
# param_2 = obj.hasNext()