class Solution:
    def maximumBeauty(self, a: List[int], m: int, target: int, full: int, partial: int) -> int:
        z = 0
        for i in a:
            if i >= target:
                z += full
        a = [i for i in a if i < target]
        if len(a) == 0:
            return z
        a.sort()
        a.append(target - 1)
        y = 0
        n = len(a)
        h = a[0]
        l = 1
        for i in range(1, n):
            t = min(m // l, a[i] - a[i - 1])
            m -= l * t
            h += t
            if h < a[l] or i == n - 1:
                break
            l += 1
        x = 0
        y = h * partial
        for i in range(n - 1)[::-1]:
            m -= target - a[i]
            x += 1
            if l > i:
                l -= 1
                m += h - a[l]
            # print(i, a[i], m, h, l)
            while m < 0 and l > 0:
                t = min(-(m // l), h - a[l - 1])
                m += l * t
                h -= t
                if h == a[l - 1]:
                    l -= 1
            if m >= 0:
                if i > 0:
                    y = max(y, h * partial + x * full)
                else:
                    y = max(y, x * full)
                # print(y, x, h, l)
        return y + z