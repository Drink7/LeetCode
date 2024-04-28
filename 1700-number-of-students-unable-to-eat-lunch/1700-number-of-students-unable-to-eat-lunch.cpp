class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // students are queue
        // sandwiches are stack
        // TC: O(n)
        // SC: O(1)
        int studentChoice[2] = {0};
        int sandwichChoice[2] = {0};
        int index = 0;
        for (auto const& num : students) {
            studentChoice[num]++;
        }

        for (auto const& num : sandwiches) {
            sandwichChoice[num]++;
        }

        if (studentChoice[0] == sandwichChoice[0]) {
            return 0;
        } else {
            while (index < sandwiches.size() && studentChoice[sandwiches[index]] > 0) {
                studentChoice[sandwiches[index]]--;
                index++;
            }
            
            return sandwiches.size() - index;
        }
    }
};