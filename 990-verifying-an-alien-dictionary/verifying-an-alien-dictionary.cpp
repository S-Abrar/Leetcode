class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {

        vector<int> pos(26);

        // Store the position of each character in alien order
        for (int i = 0; i < order.size(); i++) {
            pos[order[i] - 'a'] = i;
        }

        // Compare adjacent words
        for (int i = 0; i < words.size() - 1; i++) {

            string a = words[i];
            string b = words[i + 1];

            int j = 0;

            while (j < a.size() && j < b.size() && a[j] == b[j])
                j++;

            // Prefix case
            if (j == b.size() && a.size() > b.size())
                return false;

            // Compare first different character
            if (j < a.size() && j < b.size()) {
                if (pos[a[j] - 'a'] > pos[b[j] - 'a'])
                    return false;
            }
        }

        return true;
    }
};