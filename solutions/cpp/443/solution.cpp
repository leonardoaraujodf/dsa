class Solution {
public:
    int compress(vector<char>& chars) {
        char curr = chars[0];
        int ans = 0;
        for (int i = 0; i < chars.size();) {
            const char curr = chars[i];
            int count = 0;

            while (i < chars.size() && curr == chars[i]) {
                ++i;
                ++count;
            }

            chars[ans++] = curr;
            if (count > 1) {
                const string str = to_string(count);
                for (int j = 0; j < str.size(); j++) {
                    chars[ans++] = str[j];
                }
            }
        }

        return ans;
    }
};