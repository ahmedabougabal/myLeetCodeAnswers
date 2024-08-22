"""
take the num, convert it to binary , change 0s to 1s and 1s to 0s and then return
the decimal of it.

"""
class Solution:
    def findComplement(self, num: int) -> int:
        complement = "".join('1' if bit == '0' else '0' for bit in bin(num)[2:] )
        return int(complement,2)
          
