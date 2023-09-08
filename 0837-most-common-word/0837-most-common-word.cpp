class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        // paragraph -> lowercase
        // split paragraph with regex
        // store in hash map
        // check the banned and remove the key value by banned list
        // find the max
        // TC: O(m * n)
        // SC: O(m + n)

        // handle paragraph
        for (int i = 0; i < paragraph.size(); i++) {
            if (isalpha(paragraph[i])) {
                paragraph[i] = tolower(paragraph[i]);
            } else {
                paragraph[i] = ' ';
            }
        }

        unordered_map<string, int> strDict;
        int maxCnt = INT_MIN;
        string result = "";
        istringstream iss(paragraph);
        string lower_word;
        while (iss >> lower_word) {
            strDict[lower_word]++;
        }

        for (auto const& s : banned) {
            strDict.erase(s);
        }

        for (auto const& p : strDict) {
            cout << p.first << endl;
            if (p.second > maxCnt) {
                maxCnt = p.second;
                result = p.first;
            }
        }
        return result;
    }
};