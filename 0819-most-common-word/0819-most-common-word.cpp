class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        // trim paragraph
        // build word map <string, int>
        // remove banned word
        // traverse map, find the most common
        // TC: O(n)
        // SC: O(n)
        unordered_map<string, int> strDict;
        // make all lower case
        for (int i = 0; i < paragraph.size(); i++) {
            if (isalpha(paragraph[i])) {
                paragraph[i] = tolower(paragraph[i]);
            } else {
                paragraph[i] = ' ';
            }
        }

        stringstream ss(paragraph);
        string token;
        while (ss >> token) {
            string pure_token;
            for (auto const& c : token) {
                if (c >= 'a' && c <= 'z') {
                    pure_token += c;
                }
            }
            strDict[pure_token]++;
        }

        // remove banned word
        for (auto const& str : banned) {
            strDict.erase(str);
        }

        // traverse to find most common
        string result = "";
        int result_count = -1;
        for (auto const& p : strDict) {
            if (p.second > result_count) {
                result = p.first;
                result_count = p.second;
            }
        }
        return result;
    }
};