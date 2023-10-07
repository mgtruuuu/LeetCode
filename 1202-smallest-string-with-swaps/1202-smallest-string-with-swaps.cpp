/*
// Approach 1: Recursive DFS
class Solution {
  private:
    void dfs(const std::string& s, const std::vector<std::vector<int>>& adj_list, const int vertex,
             std::vector<bool>& visited, std::vector<char>& characters, std::vector<int>& indices)
    {
        // Add the character and index to the list
        characters.push_back(s[vertex]);
        indices.push_back(vertex);

        visited[vertex] = true;

        // Traverse the adjacents
        for (int adj : adj_list[vertex]) {

            if (visited[adj] == false) {
                dfs(s, adj_list, adj, visited, characters, indices);
            }
        }
    }

  public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs)
    {
        const auto len_s = static_cast<int>(s.size());

        std::vector<bool> visited(len_s, false);
        std::vector<std::vector<int>> adj_list(len_s);

        // Build the adjacency list
        for (const auto& edge : pairs) {

            // Undirected edge
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        for (auto vertex = 0; vertex != len_s; ++vertex) {

            // If already covered in the dfs
            if (visited[vertex] == true) {
                continue;
            }

            std::vector<char> characters;
            std::vector<int> indices;

            dfs(s, adj_list, vertex, visited, characters, indices);

            // Sort the list of characters and indices
            sort(characters.begin(), characters.end());
            sort(indices.begin(), indices.end());

            // Store the sorted characters corresponding to the index
            for (auto idx = std::size_t(0); idx != characters.size(); ++idx) {
                s[indices[idx]] = characters[idx];
            }
        }

        return s;
    }
};
*/


/*
// Approach 2: Iterative BFS
class Solution {
  public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs)
    {
        const auto len_s = static_cast<int>(s.size());

        std::vector<bool> visited(len_s, false);
        std::vector<std::vector<int>> adj_list(len_s);

        for (const auto& edge : pairs) {

            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        std::queue<int> q;

        for (auto vertex = 0; vertex != len_s; ++vertex) {

            if (visited[vertex] == true) {
                continue;
            }

            std::vector<char> characters;
            std::vector<int> indices;

            q.push(vertex);
            visited[vertex] = true;
            while (q.empty() == false) {

                const auto idx = q.front();
                q.pop();

                characters.push_back(s[idx]);
                indices.push_back(idx);

                for (const auto neighbor : adj_list[idx]) {

                    if (visited[neighbor] == false) {

                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }

            sort(characters.begin(), characters.end());
            sort(indices.begin(), indices.end());

            for (auto idx = std::size_t(0); idx != characters.size(); ++idx) {
                s[indices[idx]] = characters[idx];
            }
        }

        return s;
    }
};
*/


///*
//Approach 3: Disjoint Set Union (DSU)

class UnionFind {
  private:
    std::vector<int> m_parents;
    std::vector<int> m_ranks;

  public:
    UnionFind(const int num_nodes)
    {
        m_parents.resize(num_nodes);
        m_ranks.resize(num_nodes);

        for (auto idx = 0; idx != num_nodes; ++idx) {
            m_parents[idx] = idx;
            m_ranks[idx] = 1;
        }
    }

    int find(const int x)
    {
        if (x == m_parents[x]) {
            return x;
        }

        return (m_parents[x] = find(m_parents[x]));
    }

    void unionSet(const int x, const int y)
    {
        const auto root_x = find(x);
        const auto root_y = find(y);

        if (root_x == root_y) {
            return;
        }

        if (m_ranks[root_x] < m_ranks[root_y]) {
            m_parents[root_x] = root_y;
        }
        else if (m_ranks[root_x] > m_ranks[root_y]) {
            m_parents[root_y] = root_x;
        }
        else {
            m_parents[root_y] = root_x;
            ++m_ranks[root_x];
        }
    }

    const std::vector<int>& getParents() const
    {
        return m_parents;
    }
};

class Solution {
  public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs)
    {
        const auto len_s = static_cast<int>(s.size());

        UnionFind uf{ len_s };

        for (const auto& pair : pairs) {
            uf.unionSet(pair.front(), pair.back());
        }

        std::unordered_map<int, std::vector<int>> top2children;
        const auto& parents = uf.getParents();
        for (auto idx = 0; idx != len_s; ++idx) {

            const auto root_idx = uf.find(idx);
            top2children[root_idx].push_back(idx);
        }

        for (const auto& [k, v] : top2children) {

            std::vector<char> chars;
            chars.reserve(v.size());
            for (const auto i : v) {
                chars.push_back(s[i]);
            }

            std::sort(chars.begin(), chars.end());

            for (auto i = 0; i != static_cast<int>(v.size()); ++i) {
                s[v[i]] = chars[i];
            }
        }

        return s;
    }
};
//*/