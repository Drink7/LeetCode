class Solution {
public:
    int calPoints(vector<string>& operations) {
        // traverse and use a vector to store record
        // TC: O(n)
        // SC: O(n)
        vector<int> record;
        int result = 0;
        for (auto const& operation : operations) {
            if (operation != "C" && operation != "D" && operation != "+" ) {
                // number
                int num = stoi(operation);
                record.push_back(num);
            } else {
                if (record.size() > 0 && operation == "C") {
                    record.pop_back();
                } else if (record.size() > 0 && operation == "D") {
                    record.push_back(record.back() * 2);
                } else if (record.size() > 1 && operation == "+") {
                    int lastOne = record.size() - 1;
                    int lastTwo = record.size() - 2;
                    record.push_back(record[lastOne] + record[lastTwo]);
                }
            }
        }

        // sum up
        for (auto const& num : record) {
            result += num;
        }
        return result;
    }
};