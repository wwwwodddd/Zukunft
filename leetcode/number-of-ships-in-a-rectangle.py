# """
# This is Sea's API interface.
# You should not implement it, or speculate about its implementation
# """
#class Sea(object):
#    def hasShips(self, topRight: 'Point', bottomLeft: 'Point') -> bool:
#
#class Point(object):
#	def __init__(self, x: int, y: int):
#		self.x = x
#		self.y = y

class Solution(object):
    def countShips(self, sea: 'Sea', b: 'Point', a: 'Point') -> int:
        if a.x > b.x or a.y > b.y or not sea.hasShips(b, a):
            return 0
        if a.x == b.x and a.y == b.y:
            return 1
        xm = (a.x + b.x) // 2
        ym = (a.y + b.y) // 2
        return self.countShips(sea, Point(xm, ym), Point(a.x, a.y)) + \
               self.countShips(sea, Point(b.x, ym), Point(xm + 1, a.y)) + \
               self.countShips(sea, Point(xm, b.y), Point(a.x, ym + 1)) + \
               self.countShips(sea, Point(b.x, b.y), Point(xm + 1, ym + 1))