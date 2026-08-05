class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int i = a.size() - 1, j = b.size() - 1, carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0'; // ascii of 1 = 49, 0 = 48, hence 1 that represents the bit
            if (j >= 0) sum += b[j--] - '0';

            
            result.insert(result.begin(), (sum % 2) + '0');
            carry = sum / 2; 
        }

        return result;
    }
};
