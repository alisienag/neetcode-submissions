class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (min.empty() || val <= min.back()) {
            min.push_back(val);
        }
        vec.push_back(val);
    }
    
    void pop() {
        if (vec.back() == min.back()) {
            min.pop_back();
        }
        vec.pop_back();
    }
    
    int top() {
        return vec.back();
    }
    
    int getMin() {
        return min.back();
    }
private:
    std::vector<int> vec;
    std::vector<int> min;
};
