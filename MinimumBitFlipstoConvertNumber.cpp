#include <iostream>
#include <bitset>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        // XOR the two numbers and count the number of set bits
        return __builtin_popcount(start ^ goal);
    }
};

