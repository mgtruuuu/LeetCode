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

        if (root_x < root_y) {
            m_parents[root_x] = root_y;
        }
        else if (root_y < root_x) {
            m_parents[root_y] = root_x;
        }
        else {
            m_parents[root_x] = root_y;
            ++m_ranks[root_y];
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