su = []
x = 0
y = 0
ans = 0

for i in range(101):
    x = i * i
    su.append(x)
    y += i
    i+=1
y = y * y
ans = y - sum(su)
print(ans)

