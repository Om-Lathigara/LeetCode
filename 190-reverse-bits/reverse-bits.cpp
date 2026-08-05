class Solution {
public:
    int reverseBits(int n) {
        unsigned int result = 0;

        for (int i = 0; i < 32; i++) {
            result <<= 1;          // Make space for the next bit
            result |= (n & 1);     // Copy the last bit of n
            n >>= 1;               // Move to the next bit
        }

        return result;
    }
};