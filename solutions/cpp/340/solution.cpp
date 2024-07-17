class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<int, int> count;
        int left = 0;
        int ans = 0;
        for (int right = 0; right < s.size(); right++) {
            count[s[right]]++;
            while (count.size() > k) {
                count[s[left]]--;
                if (count[s[left]] == 0) {
                    count.erase(s[left]);
                }
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};