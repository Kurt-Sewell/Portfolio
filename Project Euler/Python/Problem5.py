safe = 1
number = 20
numcheck = [11, 12, 13, 14, 15, 16, 17, 18, 19, 20]

while safe == 1:
    check = []

    for i in reversed(range(len(numcheck))):
        remainder = number % (numcheck[i])

        if remainder == 0:
            check.append('Good')
        else:
            check.append('Bad')
            break

    if 'Bad' not in check:
        safe = 0
        print(number)

    number += 20
