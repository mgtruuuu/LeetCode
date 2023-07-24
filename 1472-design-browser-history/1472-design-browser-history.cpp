class BrowserHistory {
  private:
    std::vector<std::string> homepages;
    int idx_curr;
    
  public:
    BrowserHistory(string homepage)
    {
        homepages.clear();
        
        idx_curr = -1;
        visit(std::move(homepage));
    }

    void visit(string url)
    {
        homepages.resize(idx_curr + 2);
        homepages[idx_curr + 1] = std::move(url);
        ++idx_curr;
    }

    string back(int steps)
    {
        idx_curr = std::max(0, idx_curr - steps);
            
        return homepages[idx_curr];
    }

    string forward(int steps)
    {   
        idx_curr = std::min(static_cast<int>(homepages.size()) - 1, idx_curr + steps);
        
        return homepages[idx_curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */