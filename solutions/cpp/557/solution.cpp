class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        for (int right = 0; right <= s.size(); right++) {
            if (right == s.size()) {
                reverse(left, right - 1, s);
            } else if (s[right] == ' ') {
                reverse(left, right - 1, s);
                left = right + 1;
            }
        }

        return s;
    }

    void reverse(int left, int right, string &s) {
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};