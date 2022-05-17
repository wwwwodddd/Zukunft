class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        return int("{0:{fill}32b}".format(n, fill='0')[::-1], 2)
        