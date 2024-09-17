prime = 0
check = []
number = 3
passed = 1

while passed < 10001:
    check = []

    for i in range(2, number):

        if number % i == 0:
            check.append('False')
            break
        else:
            check.append('True')

    if 'False' not in check:
        prime = number
        passed += 1
    
    number += 1

print(prime, 'is the', passed, 'Prime Number')