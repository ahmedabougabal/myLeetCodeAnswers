class Solution:
    def minimumDeletions(self, s: str) -> int:
        deletions =0
        bCount=0
        for char in s:
            if char == 'a':
                if bCount > deletions:
                    deletions+=1  
            else:
                bCount+= 1
            return deletions