class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        // Swap 16-bit halves
        n = ((n & 0xFFFF0000) >> 16) | ((n & 0x0000FFFF) << 16);

        // Swap 8-bit blocks
        n = ((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8);

        // Swap 4-bit blocks (nibbles)
        n = ((n & 0xF0F0F0F0) >> 4) | ((n & 0x0F0F0F0F) << 4);

        // Swap 2-bit blocks
        n = ((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2);

        // Swap individual bits
        n = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);

        return n;
    }
};