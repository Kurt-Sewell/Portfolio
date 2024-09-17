list = [1, 2]
evlist = []
up = 0
failsafe = 1

while failsafe == 1:
    x = list[up] + list[up+1]
    rem = x % 2
    if x < 4000000:
        list.append(x)
    else:
        for i in range(len(list)):
            rem = list[i] % 2
            if rem == 0:
                evlist.append(list[i])
        print(sum(evlist))
        print(evlist)
        print(list)
        failsafe = 0
    up += 1
