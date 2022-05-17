class Solution:
    def minimumRefill(self, p: List[int], ca: int, cb: int) -> int:
        da = ca
        db = cb
        z = 0
        for i in range(len(p) // 2):
            if da < p[i]:
                da = ca
                z += 1
            da -= p[i]
            if db < p[len(p) - 1 - i]:
                db = cb
                z += 1
            db -= p[len(p) - 1 - i]
        if len(p) & 1:
            if max(da, db) < p[len(p) // 2]:
                z += 1
        return z