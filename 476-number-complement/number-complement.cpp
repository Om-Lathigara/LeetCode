class Solution {
public:
    int findComplement(int num) {
        int complement = 0;
        int position = 0;

        while (num > 0) {
            int bit = num & 1;
            complement |= ((bit ^ 1) << position);
            num >>= 1;
            position++;
        }

        return complement;
    }
};