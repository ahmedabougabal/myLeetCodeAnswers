# this is the codeWars version (won't work on leetcode
# as of different problem requirements )

from collections import deque


def valid_parentheses(string):
    stack = deque()
    s = len(string)
    for i in range(s):
        if string[i] == "(":
            stack.append(string[i])
        else:
            if string[i] != "(" and string[i] != ")":
                continue
            if not stack:  # checks if the stack is empty
                return False
            else:
                stack.pop()

    if stack:
        return False
    else:
        return True
