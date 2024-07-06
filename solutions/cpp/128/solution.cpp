class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> count;
        for (int num : nums) {
            count.insert(num);
        }
        int longest = 0;
        while (count.size()) {
            int start;
            for (int num : count) {
                if (count.find(num - 1) == count.end()) {
                    start = num;
                    break;
                }
            }
            int lenSoFar = 1;
            count.erase(start);
            while (count.find(start + 1) != count.end()) {
                count.erase(start + 1);
                lenSoFar++;
                start++;
            }
            longest = max(longest, lenSoFar);
        }
        return longest;
    }
};