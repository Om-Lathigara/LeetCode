class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        unsigned int n = num;
        string hex = "";
        string chars = "0123456789abcdef";
        
        while (n > 0) {
            hex.push_back(chars[n & 0xF]);
            n >>= 4;
        }
        
        reverse(hex.begin(), hex.end());
        return hex;
    }
};