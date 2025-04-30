from functools import cache


class Solution:
    @cache
    def climbStairs(self, n: int) -> int:
        total = 0
        if n == 0 or n == 1:
            return 1
        total = self.climbStairs(n - 1) + self.climbStairs(n - 2)
        return total
