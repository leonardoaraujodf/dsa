constexpr int MAX_HOT_DEGREE = 3;

class AutocompleteSystem {
public:
    struct compare {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
            // If times are different, prioritize higher times
            if (a.first != b.first) {
                return a.first > b.first;
            }
            // If times are the same, prioritize lexicographically smaller sentence
            return a.second < b.second;
        }
    };

    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        TrieNode() : children(unordered_map<char, TrieNode*>()) {};
        priority_queue<pair<int, string>, vector<pair<int, string>>, compare> heap;
    };

    TrieNode *root;
    string actualSentence;
    TrieNode *actualNode;
    unordered_map<string, int> sentencesCount;
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        actualNode = root;
        for (int i = 0; i < sentences.size(); i++) {
            sentencesCount[sentences[i]] = times[i];
            TrieNode *node = root;
            for (char c : sentences[i]) {
                if (node->children.find(c) == node->children.end()) {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
                node->heap.push(pair(times[i], sentences[i]));
                if (node->heap.size() > 3) {
                    node->heap.pop();
                }
            }
        }
    }

    vector<string> input(char c) {
        vector<string> ans;
        if (c == '#') {
            this->treatEndOfSentence();
            return ans;
        }

        if (actualNode->children.find(c) != actualNode->children.end()) {
            // Update actualNode
            actualNode = actualNode->children[c];
            auto nodeHeap = actualNode->heap;
            ans = vector<string>(nodeHeap.size(), string());
            int ansIdx = ans.size() - 1;
            while(nodeHeap.size() > 0) {
                ans[ansIdx] = nodeHeap.top().second;
                nodeHeap.pop();
                ansIdx--;
            }
        } else {
            actualNode->children[c] = new TrieNode();
            actualNode = actualNode->children[c];
        }
        // Update actualSentence
        actualSentence.push_back(c);

        return ans;
    }

    void treatEndOfSentence(void) {
        sentencesCount[actualSentence]++;
        TrieNode *node = root;
        for (char c : actualSentence) {
            node = node->children[c];

            vector<pair<int, string>> values;
            bool found = false;
            while (node->heap.size() > 0) {
                auto val = node->heap.top();
                // Check if actual sentence is already in the heap.
                // If that is the case we need to update its value.
                if (val.second == actualSentence) {
                    found = true;
                    val.first++;
                }
                values.push_back(val);
                node->heap.pop();
            }

            if (!found) {
                // If new sentence was not in the heap we need to add it to the heap
                values.push_back(make_pair(sentencesCount[actualSentence], actualSentence));
            }

            // Add updated sentences to the node heap
            for (auto &val : values) {
                node->heap.push(val);
            }

            while (node->heap.size() > MAX_HOT_DEGREE) {
                node->heap.pop();
            }
        }
        // Reset actual node and actual sentence
        actualNode = root;
        actualSentence.erase();
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */