class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;

        while (n > 0) {
            if (n & 1) {      // If the last bit is 1
                count++;
            }
            n = n >> 1;       // Move to the next bit
        }

        return count;
    }
};