class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0) {
            return true;
        }

        if (t.size() == 0 || s.size() > t.size()) {
            return false;
        }

        int left = 0;
        for (int right = 0; right < t.size(); right++) {
            if (s[left] == t[right]) {
                left++;
                if (left == s.size()) {
                    return true;
                }
            }
        }

        return false;
    }
};