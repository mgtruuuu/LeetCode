class Solution {
public:
    std::vector<std::vector<int>> verticalOrder(TreeNode* root) {
        std::vector<std::vector<int>> output;
        if (root == NULL) {
            return output;
        }

        std::map<int, std::vector<int>> columnTable;
        std::queue<std::pair<TreeNode*, int>> queue;
        int column = 0;
        queue.push(std::make_pair(root, column));

        while (!queue.empty()) {
            std::pair<TreeNode*, int> p = queue.front();
            queue.pop();
            root = p.first;
            column = p.second;

            if (root != NULL) {
                if (columnTable.find(column) == columnTable.end()) {
                    columnTable[column] = std::vector<int>();
                }
                columnTable[column].push_back(root->val);

                queue.push(std::make_pair(root->left, column - 1));
                queue.push(std::make_pair(root->right, column + 1));
            }
        }

        for(auto const& pair: columnTable) {
            output.push_back(pair.second);
        }

        return output;
    }
};