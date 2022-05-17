class Solution:
    def alertNames(self, keyName: List[str], keyTime: List[str]) -> List[str]:
        g = {}
        z = set()
        for time, name in sorted(zip(keyTime, keyName)):
            if name not in g:
                g[name] = []
            hh, mm = time.split(':')
            g[name].append(int(hh) * 60 + int(mm))
            if len(g[name]) >= 3 and g[name][-1] - g[name][-3] <= 60:
                z.add(name)
        return sorted(list(z))