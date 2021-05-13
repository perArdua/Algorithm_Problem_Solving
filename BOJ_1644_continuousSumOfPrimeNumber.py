import sys
from math import ceil, sqrt
input = sys.stdin.readline

n = int(input())
is_prime = [False, False] + [True] * (n - 1)

for i in range(2, ceil(sqrt(n)) + 1):
    if is_prime[i]:
        j = 2
        while i * j <= n:
            is_prime[i * j] = False
            j += 1
primes = [i for i in range(2, n + 1) if is_prime[i]]
lo = 0
hi = 0
cur_sum = 0
cnt = 0
len_primes = len(primes)

while True:
    if cur_sum >= n:
        if cur_sum == n:
            cnt += 1
        cur_sum -= primes[lo]
        lo += 1
    elif hi == len_primes:
        break
    else:
        cur_sum += primes[hi]
        hi += 1
print(cnt)
