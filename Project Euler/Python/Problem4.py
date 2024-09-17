score = 0

for i in reversed(range(1000)):
    for k in reversed(range(1000)):
        product = i * k
        if product > score:
            temp = []

            for a in range(len(str(product))):
                temp.append(str(product)[a])

            if temp == list(reversed(temp)):
                print(':)')
                score = product



print(score)
