class DetectSquares {
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        dict[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int x1 = point[0];
        int y1 = point[1];
        // traverse points
        int result = 0;
        for (auto const& Xs : dict) {
            int x2 = Xs.first;
            for (auto const& Ys : Xs.second) {
                int y2 = Ys.first;
                if (x1 == x2 || y1 == y2) {
                    continue;
                }


                int length = abs(x1 - x2);
                if (abs(y1 - y2) != length) { 
                    // not square
                    continue;
                }

                // check the other two points and count
                if (dict.count(x1) < 1 || dict[x1].count(y2) < 1 ||
                    dict.count(x2) < 1 || dict[x2].count(y1) < 1) {
                    continue;
                }
                result += dict[x2][y2] * dict[x1][y2] * dict[x2][y1];
            }
        }
        return result;
    }
    // hash map
    // map<pair<int, int>, int> dict;
private:
    //map<pair<int, int>, int> dict;
    unordered_map<int, unordered_map<int, int>> dict;
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */