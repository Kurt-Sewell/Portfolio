list = []

def three(x):
    global list
    rem = x % 3
    if rem == 0:
        list.append(x)
        
def five(x):
    global list
    rem = x % 5
    if rem == 0 and x not in list:
        list.append(x)

for i in range(1000):
    three(i)
    five(i)

print(sum(list))
print(list)
