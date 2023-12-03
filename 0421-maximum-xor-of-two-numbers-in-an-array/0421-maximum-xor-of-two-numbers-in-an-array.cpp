struct TrieNode {
    TrieNode* children[2] = {nullptr, nullptr};
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        
        int L = 0;
        while (maxNum != 0) {
            ++L;
            maxNum >>= 1;
        }
        
        int maxXor = 0;

        TrieNode* root = new TrieNode();
        for (int num: nums) {
            TrieNode* node = root;
            TrieNode* xorNode = root;
            int currXor = 0;
            
            for (int i = L - 1; i >= 0; --i) {
                int bit = (num >> i) & 1;
                int toggledBit = bit ^ 1;
                
                if (node->children[bit] == nullptr) {
                    TrieNode* newNode = new TrieNode();
                    node->children[bit] = newNode;
                }
                node = node->children[bit];
                
                if (xorNode->children[toggledBit] != nullptr) {
                    currXor |= (1 << i);
                    xorNode = xorNode->children[toggledBit];
                } else {
                    xorNode = xorNode->children[bit];
                }
            }
            maxXor = max(maxXor, currXor);
        }
        
        return maxXor;
    }
};