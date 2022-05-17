class MinStack(object):
    def __init__(self):
        self.s = [0]
        self.a = [2 ** 40]
        """
        initialize your data structure here.
        """
        

    def push(self, x):
        self.s.append(x)
        self.a.append(min(x, self.a[-1]))
        """
        :type x: int
        :rtype: nothing
        """
        

    def pop(self):
        del self.s[-1]
        del self.a[-1]
        """
        :rtype: nothing
        """
        

    def top(self):
        return self.s[-1]
        """
        :rtype: int
        """
        

    def getMin(self):
        return self.a[-1]
        """
        :rtype: int
        """
        