class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        // TC: O(1)
        // SC: O(1)
        long long volume = (long long) length * (long long) width * (long long) height;
        if (length >= bulky_dimenstion_base || width >= bulky_dimenstion_base ||
            height >= bulky_dimenstion_base || volume >= bulky_volume_base) {
            // bulky or neither
            if (mass >= 100) {
                return "Both";
            } else {
                return "Bulky";
            }
        } else {
            // heavy or both
            if (mass >= 100) {
                return "Heavy";
            } else {
                return "Neither";
            }
        }
    }
private:
    int bulky_dimenstion_base = 10000;
    long bulky_volume_base = 1000000000;
};