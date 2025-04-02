class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int size = max(word1.size(), word2.size());
        string result;
        for (int i = 0; i < size; i++) {
            if (word1[i])
                result += word1[i];
            if (word2[i])
                result += word2[i];
        }
    }
};