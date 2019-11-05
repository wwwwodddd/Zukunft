print max(map(lambda s:sum(map(int,list(str(s)))),[a**b for a in range(2,101) for b in range(2,101)]))

