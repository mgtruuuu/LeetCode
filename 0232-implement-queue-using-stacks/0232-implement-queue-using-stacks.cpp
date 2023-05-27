class MyQueue {
private:
    std::stack<int> s1;
    std::stack<int> s2;
    int front;


public:
    MyQueue()
    {
    }

    void push(int x) 
    {
        if (s1.empty() == true)
        {
            front = x;
        }
        
        s1.push(x);
    }

    int pop() 
    {
        if (s2.empty() == true)
        {
            while (s1.empty() == false)
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        const auto res = s2.top();
        s2.pop();
        return res;
    }

    int peek() 
    {
        int res;

        if (s2.empty() == true)
        {
            res = front;
        }
        else
        {
            res = s2.top(); 
        }

        return res;
    }

    bool empty() 
    {
        return (s1.empty() == true && s2.empty() == true);
    }
};