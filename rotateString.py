class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        substring = s[0]
        index = s.index(substring)
        new_s = s[:index] + s[index+len(substring):] + substring
        return sorted(new_s) == sorted(goal) and len(s) == len(goal) and goal in (s+s)