/*
// Approach 1: Two Stacks
class BrowserHistory {
  private:
    std::stack<std::string> history;
    std::stack<std::string> future;
    std::string curr;
    
  public:
    BrowserHistory(string homepage)
    {
        curr = std::move(homepage);
    }

    void visit(string url)
    {
        history.push(curr);
        curr = std::move(url);
        
        future = std::stack<std::string>();
    }

    string back(int steps)
    {
        while (steps > 0 && history.empty() == false) {
            future.push(curr);
            curr = history.top();
            history.pop();
            --steps;
        }
        
        return curr;
    }

    string forward(int steps)
    {
        while (steps > 0 && future.empty() == false) {
            history.push(curr);
            curr = future.top();
            future.pop();
            --steps;
        }
        
        return curr;
    }
};
*/



class DLLNode {
  public:
    std::string m_data;
    DLLNode* m_prev;
    DLLNode* m_next;

    DLLNode(string url) : m_data{ std::move(url) }, m_prev{ nullptr }, m_next{ nullptr }
    {
    }
};

// Approach 2: Doubly Linked List
class BrowserHistory {

  private:
    DLLNode* linkedListHead;
    DLLNode* curr;

  public:
    BrowserHistory(string homepage)
    {
        linkedListHead = new DLLNode{ homepage };
        curr = linkedListHead;
    }

    void visit(string url)
    {
        if (curr->m_next != nullptr) {

            auto* trash = curr->m_next;

            do {
                auto* next = trash->m_next;
                delete trash;
                trash = next;
                
            } while (trash != nullptr);
        }

        curr->m_next = new DLLNode{ url };
        curr->m_next->m_prev = curr;
        curr = curr->m_next;
    }

    string back(int steps)
    {
        while (steps-- != 0) {

            if (curr->m_prev == nullptr) {
                break;
            }

            curr = curr->m_prev;
        }

        return curr->m_data;
    }

    string forward(int steps)
    {
        while (steps-- != 0) {

            if (curr->m_next == nullptr) {
                break;
            }

            curr = curr->m_next;
        }

        return curr->m_data;
    }
};



/*
// Approach 3: Dynamic Array
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
*/

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */