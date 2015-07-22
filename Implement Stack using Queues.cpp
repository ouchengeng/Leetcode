class Stack {
private:
    queue<int> q;
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        queue<int> tmp;
        int size = q.size();
        for(int i = 0; i < size - 1; i++)
        {
            tmp.push(q.front());
            q.pop();
        }
        q = tmp;
    }

    // Get the top element.
    int top() {
        return q.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
    
};