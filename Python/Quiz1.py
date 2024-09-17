def fizz_buzz(x):
    output = ''
    if (x % 3 == 0):
        output += 'Fizz'
    if (x % 5 == 0):
        output += 'Buzz'

    if (output != ''):
        return output
    else:
        return x


print(fizz_buzz(3))
