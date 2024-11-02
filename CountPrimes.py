#Prime numbers are natural numbers greater than 1 that 
# have no divisors other than 1 and themselves
# Examples of prime numbers: 2, 3, 5, 7, 11, 13, 17, 19, 23...
import math


class Solution:
    def countPrimes(self, n: int, i=None) -> int:
        # create a list of size n and has a default value of true
        if (n <= 2):
            return 0
        isPrime = [True] * (n)
        isPrime[0] = isPrime[1] = False
        for i in range(2, int(math.sqrt(n)) + 1):
            if isPrime[i]:
                for j in range(i * i, n, i):
                    isPrime[j] = False

        count = 0
        for i in range(2, n):
            if (isPrime[i]):
                count = count + 1
        return count
