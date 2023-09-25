class Solution {
  public:
    string convertToTitle(int columnNumber)
    {   
        std::string title;
        while (columnNumber-- != 0) {
            
            const auto n = columnNumber;
            columnNumber /= 26;
            const auto r = n - columnNumber * 26;
            
            title.push_back(r + 'A');
        }
        
        std::reverse(title.begin(), title.end());
        
        return title;
    }
};