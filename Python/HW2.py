import numpy as np
import matplotlib.pyplot as plt
import re


def Problem1():
    t = np.linspace(0.1, 0.25, 10)

    y = ((6*(t**3) - 3*t - 4) / (8*np.sin(5*t)))

    chart = plt.subplot()
    chart.plot(t, y)

    plt.show()


def Problem2():
    t = np.linspace(1, 5, 10)

    y = ((3*t - 2) / (4*t)) - ((np.pi / 2)*t)
    print(type(y))

    chart = plt.subplot()
    chart.plot(t, y)

    plt.show()


def piecewise(t):
    y = np.zeros_like(t)
    y = np.where((0 <= t) & (t <= 8), (10*(t**2)) - 5*t, y)
    y = np.where((8 < t) & (t < 16), (624 - 3*t), y)
    y = np.where((16 < t) & (t <= 26), (36*t + 12*((t - 16)**2)), y)
    y = np.where((t > 26), 2136*np.exp(-0.1*(t-26)), y)
    return y


def Problem3():
    time_points = np.linspace(-5, 50, 200)

    out = piecewise(time_points)

    piecewise_plot = plt.subplot()
    piecewise_plot.plot(time_points, out)

    plt.show()


def rounder(x, n):
    if not isinstance(x, list):
        x = [x]
    if not isinstance(n, list):
        n = [n]
    out = []
    for i, j in zip(x, n):
        if j >= 0:
            fact = 10 ** j
            out.append(int((i * fact)+0.5) / fact)
        else:
            fact = 10 ** (-j)
            out.append(int((i / fact)+0.5) * fact)

    return out


def Problem4():
    x = [477.9587, 477.958, 7, 0.125, 0.362945, 8192, 135784]
    n = [2, 2, 0, 2, 4, -1, -3]

    print(rounder(x, n))


def days(mo, day, leap):
    out = 0
    for i in range(0, mo):
        if (i == 1 or i == 3 or i == 5 or i == 7 or i == 8 or i == 10 or i == 12):
            print(i)
            out += 31
        elif (i == 4 or i == 6 or i == 9 or i == 11):
            print(i)
            out += 30
        elif (i == 2):
            print(i)
            if (leap == False):
                out += 28
            elif (leap == True):
                out += 29
        else:
            continue
    out += day
    return out


def Problem5():
    mo = 3
    day = 1
    leap = False

    print(days(mo, day, leap))


def is_leap_year(year):
    if year % 100 == 0:
        if year % 400 == 0:
            return False
        else:
            return True
    else:
        if year % 4 == 0:
            return True
        else:
            return False


def Problem6():
    print(is_leap_year(1900))
    print(is_leap_year(2000))


def sinefunc(t, ybar, ydel, f, phi):
    y = ybar + ydel*np.sin(2*np.pi*f*t - phi)
    return y


def cosinefunc(t, ybar, ydel, f, phi):
    y = ybar + ydel*np.cos(2*np.pi*f*t - phi)
    return y


def Problem7():
    t = np.linspace(0, 2*np.pi, 100)
    case1_3pi = sinefunc(t, 0, 1, 1.5, 0)
    case1_2pi = sinefunc(t, 0, 1, 1, 0)

    case2_base = sinefunc(t, 0, 1, 1, 0)
    case2_shift = sinefunc(t, 0, 1, 1, (np.pi/4))

    case3_base = sinefunc(t, 0, 1, 1, 0)
    case3_change = sinefunc(t, 0.5, 1.2, 1, 0)

    case4_base = sinefunc(t, 0, 1, 1, 0)
    case4_cos = cosinefunc(t, 0, 1, 1, (np.pi/2))

    polar = sinefunc(t, 0, 1, 1, 0)

    fig, axs = plt.subplots(2, 3, figsize=(15, 10))
    chart1 = axs[0, 0]
    chart1.plot(t, case1_3pi, label='3π')
    chart1.plot(t, case1_2pi, label='2π')
    chart1.legend()
    chart1.set_title('Case 1: Sine Functions')

    chart2 = axs[0, 1]
    chart2.plot(t, case2_base, label='Base')
    chart2.plot(t, case2_shift, label='Shifted')
    chart2.legend()
    chart2.set_title('Case 2: Sine Function Shift')

    chart3 = axs[0, 2]
    chart3.plot(t, case3_base, label='Base')
    chart3.plot(t, case3_change, label='Changed Amplitude/Phase')
    chart3.legend()
    chart3.set_title('Case 3: Amplitude/Phase Change')

    chart4 = axs[1, 0]
    chart4.plot(t, case4_base, label='Base')
    chart4.plot(t, case4_cos, label='Cosine')
    chart4.legend()
    chart4.set_title('Case 4: Sine vs Cosine')

    polar_chart = fig.add_subplot(2, 3, 5, projection='polar')
    polar_chart.plot(t, polar)
    polar_chart.set_title('Polar Plot')

    plt.show()


def caesar_cipher(text, shift):
    out = ""
    strtoInt = {'A': 1, 'B': 2, 'C': 3, 'D': 4, 'E': 5, 'F': 6, 'G': 7, 'H': 8,
                'I': 9, 'J': 10, 'K': 11, 'L': 12, 'M': 13, 'N': 14, 'O': 15,
                'P': 16, 'Q': 17, 'R': 18, 'S': 19, 'T': 20, 'U': 21, 'V': 22,
                'W': 23, 'X': 24, 'Y': 25, 'Z': 26}

    inttoStr = {i: j for j, i in strtoInt.items()}

    for letter in text:
        if letter == ' ':
            out += letter
            continue
        num = strtoInt.get(letter)
        num += shift
        if num > 26:
            num -= 26
        if num <= 0:
            num = 26 + num
        out += (inttoStr.get(num))

    return out


def Problem8():
    text = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG"
    print(text)
    print(caesar_cipher(text, -5))
    print(caesar_cipher(text, 16))


def remove(word):
    return re.sub(r'[^a-zA-Z0-9\']', '', word)


def analyze_text(filename="t8.shakespeare.txt"):
    word_counts = {}
    with open(filename, 'r') as file:
        for line in file:
            for word in line.split():
                remove(word)
                if (word in word_counts):
                    word_counts[word] += 1
                else:
                    word_counts[word] = 1

    sort = sorted(word_counts.items(), key=lambda i: i[1], reverse=True)

    most_common_words = sort[:25]
    return most_common_words


def Problem9():
    filename = "t8.shakespeare.txt"
    print(analyze_text(filename))


Problem9()
