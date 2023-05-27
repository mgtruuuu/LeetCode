#include <queue>


class MyStack {
private:
    std::queue<int> q1;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        q1.push(x);

        auto length = q1.size();

        while (--length > 0)
        {
            q1.push(q1.front());
            q1.pop();
        }
    }

    int pop()
    {
        const auto res = q1.front();

        q1.pop();

        return res;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};