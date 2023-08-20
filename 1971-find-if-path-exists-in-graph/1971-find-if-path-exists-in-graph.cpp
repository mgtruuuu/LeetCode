// Approach 3: Depth First Search (DFS): Iterative
class Solution {
  public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        std::vector<std::vector<int>> adjacency_list(n);

        for (std::vector<int> edge : edges) {
            adjacency_list[edge[0]].push_back(edge[1]);
            adjacency_list[edge[1]].push_back(edge[0]);
        }

        std::stack<int> st;
        st.push(source);
        std::vector<bool> seen(n, false);

        while (st.empty() == false) {

            const auto node = st.top();
            st.pop();

            if (node == destination) {
                return true;
            }

            if (seen[node] == true) {
                continue;
            }

            seen[node] = true;
            for (const auto i : adjacency_list[node]) {
                st.push(i);
            }
        }

        return false;
    }
};