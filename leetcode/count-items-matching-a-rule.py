class Solution:
    def countMatches(self, items: List[List[str]], ruleKey: str, ruleValue: str) -> int:
        s = 0
        for item in items:
            if item[['type','color','name'].index(ruleKey)] == ruleValue:
                s += 1
        return s