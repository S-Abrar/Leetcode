class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        int start = 0, maxLen = 1;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                --left;
                ++right;
            }
            // after loop, palindrome is (left+1 ... right-1)
            int len = right - left - 1;
            if (len > maxLen) {
                maxLen = len;
                start = left + 1;
            }
        };

        for (int i = 0; i < n; ++i) {
            // odd length: center at i
            expand(i, i);
            // even length: center between i and i+1
            expand(i, i + 1);
        }

        return s.substr(start, maxLen);
    }
};
