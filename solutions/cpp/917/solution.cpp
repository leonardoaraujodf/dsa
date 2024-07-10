class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            while (!(s[left] >= 'A' && s[left] <= 'Z' ||
                s[left] >= 'a' && s[left] <= 'z')) {
                left++;
                if (left >= right) {
                    break;
                }
            }
            while (!(s[right] >= 'A' && s[right] <= 'Z' ||
                s[right] >= 'a' && s[right] <= 'z')) {
                right--;
                if (left >= right) {
                    break;
                }
            }
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};