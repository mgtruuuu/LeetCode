/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
  private:
    int longestPath(Node* node, int& diameter)
    {
        if (node->children.empty() == true) {
            return 1;
        }
        else if (node->children.size() == 1) {

            const auto path_child = longestPath(node->children.front(), diameter);
            if (diameter < path_child) {
                diameter = path_child;
            }

            return path_child + 1;
        }

        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

        for (auto* child : node->children) {

            pq.push(longestPath(child, diameter));

            if (pq.size() == std::size_t(3)) {
                pq.pop();
            }
        }

        const auto path_max_second = pq.top();
        pq.pop();
        const auto path_max_first = pq.top();

        if (diameter < path_max_first + path_max_second) {
            diameter = path_max_first + path_max_second;
        }

        return path_max_first + 1;
    }

  public:
    int diameter(Node* root)
    {
        auto diameter = 0;
        longestPath(root, diameter);
        return diameter;
    }
};