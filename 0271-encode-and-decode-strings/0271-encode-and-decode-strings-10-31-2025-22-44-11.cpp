class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        // use num with a comma to represent a single string
        string result = "";
        for (auto const& str : strs) {
            result += to_string(str.size()) + "," + str;
        }
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) { // 5,Hello5,World
        vector<string> result;

        int index = 0;
        int n = s.size(); // 14
        while (index < n) { // 0 < 14
            // check string number
            string numStr = "";
            while (s[index] != ',') {
                numStr += s[index++];
            }

            // go to the next char of ,
            index++;
            int numLen = stoi(numStr);

            string tmp = "";
            while (numLen > 0) {
                tmp += s[index++];
                numLen--;
            }
            result.push_back(tmp);
        }
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));