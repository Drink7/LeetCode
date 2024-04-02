class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // TC: O(n * m), n rooms and m is the average key number
        // SC: O(n * m)
        unordered_set<int> roomUnlocked;

        // Find all sources
        // must start from room[0]
        queue<int> sources;
        sources.push(0);
        while(!sources.empty()) {
            int key = sources.front();
            sources.pop();

            if (roomUnlocked.count(key) > 0) {
                continue;
            } else {
                roomUnlocked.insert(key);
                for (int i = 0; i < rooms[key].size(); i++) {
                    sources.push(rooms[key][i]);
                }
            }
        }
        return rooms.size() == roomUnlocked.size();
    }
};