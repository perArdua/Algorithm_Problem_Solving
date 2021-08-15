from math import factorial
mod = int(1e9) + 7

def catal(num):
    return factorial(2 * num) // (factorial(num) * factorial(num + 1))

print(catal(int(input())) % mod)


