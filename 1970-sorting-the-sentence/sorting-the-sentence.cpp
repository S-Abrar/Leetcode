class Solution {
public:
    string sortSentence(string s) {
        vector<string> ans(10);
        string temp;
        int count = 0, index = 0;

        while (index < s.size()) {
            if (s[index] == ' ') {
                int pos = temp[temp.size() - 1] - '0';
                temp.pop_back();
                ans[pos] = temp;
                temp.clear();
                count++;
                index++;
            } else {
                temp += s[index];
                index++;
            }
        }

        // handle last word (no space after it)
        if (!temp.empty()) {
            int pos = temp.back() - '0';
            temp.pop_back();
            ans[pos] = temp;
            count++;
        }

        temp.clear();
        for (int i = 1; i <= count; i++) {
            temp += ans[i];
            temp += " ";
        }

        temp.pop_back(); // remove extra space
        return temp;
    }
};