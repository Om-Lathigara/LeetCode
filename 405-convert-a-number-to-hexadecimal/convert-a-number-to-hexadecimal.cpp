class Solution {
public:
    string toHex(int num) {
        if (num == 0)
            return "0";

        unsigned int n = num;
        string ans = "";
        string hex = "0123456789abcdef";

        while (n > 0) {
            int digit = n % 16;
            ans += hex[digit];
            n = n / 16;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};