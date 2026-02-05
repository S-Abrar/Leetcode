#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        vector<string> words(10); // max 9 words
        string word;
        stringstream ss(s);

        while (ss >> word) {
            int pos = word.back() - '0';  // position
            word.pop_back();              // remove number
            words[pos] = word;
        }

        string result;
        for (int i = 1; i < 10; i++) {
            if (words[i].empty()) break;
            if (!result.empty()) result += " ";
            result += words[i];
        }

        return result;
    }
};
