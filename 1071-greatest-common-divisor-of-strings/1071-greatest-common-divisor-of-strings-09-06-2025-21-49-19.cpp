class Solution {
public:
    /*
    string gcdOfStrings(string str1, string str2) {
        // Find gcd string
        if (str1.size() < str2.size()) {
            return findGcdStr(str2, str1);
        } else {
            return findGcdStr(str1, str2);
        }
    }

    string findGcdStr(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();
        
        if (n2 == 0) {
            return str1;
        }

        // find gcd str
        int cnt = 0;
        for (int i = 0; i < n2; i++) {
            if (str1[i] == str2[i]) {
                cnt++;
            }
        }

        if (cnt == n2) {
            string newStr1 = str1.substr(n2);
            if (newStr1.size() > str2.size()) {
                return findGcdStr(newStr1, str2);
            } else {
                return findGcdStr(str2, newStr1);
            }
        } else {
            return "";
        }
    }
    */
    string gcdOfStrings(string str1, string str2) {
        // God Mode
        return (str1 + str2 == str2 + str1) ? str1.substr(0, gcd(str1.size(), str2.size())) : "";
    }
};