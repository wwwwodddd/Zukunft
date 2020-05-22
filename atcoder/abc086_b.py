n = int(raw_input().replace(' ', ''))
print ['No', 'Yes'][int(n**0.5+0.5)**2==n]