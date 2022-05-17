"""
# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates
"""

class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        for e in employees:
            if e.id == id:
                z = e.importance
                for s in e.subordinates:
                    z += self.getImportance(employees, s)
                return z