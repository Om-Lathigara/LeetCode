class Solution {
public:

    string solve(string &s, int left, int right) {

        if (left >= right)
            return "";

        for (int i = left; i <= right; i++) {

            bool lower = false;
            bool upper = false;

            for (int j = left; j <= right; j++) {

                if (s[j] == tolower(s[i]))
                    lower = true;

                if (s[j] == toupper(s[i]))
                    upper = true;
            }

            if (!lower || !upper) {

                string a = solve(s, left, i - 1);
                string b = solve(s, i + 1, right);

                if (a.length() >= b.length())
                    return a;
                else
                    return b;
            }
        }

        return s.substr(left, right - left + 1);
    }

    string longestNiceSubstring(string s) {
        return solve(s, 0, s.length() - 1);
    }
};