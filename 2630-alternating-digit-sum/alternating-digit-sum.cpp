class Solution {
public:
    int alternateDigitSum(int n) {
        int sum = 0;
        int sign = 1;

        while (n > 0) {
            int digit = n % 10;
            sum += digit * sign;

            n = n / 10;
            sign = -sign;
        }

        if (sign == 1)
            sum = -sum;

        return sum;
    }
};