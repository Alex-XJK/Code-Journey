class Node {
    public int data;
    public int min;
}

class MinStack {
    
    private final Stack<Node> stack;

    public MinStack() {
        stack = new Stack<>();
    }
    
    public void push(int val) {
        int curMin = 0;
        if(this.stack.isEmpty()){
            curMin = val;
        }
        else {
            if(val < this.stack.peek().min){
                curMin = val;
            }
            else {
                curMin = this.stack.peek().min;
            }
        }

        Node n = new Node();
        n.data = val;
        n.min = curMin;
        this.stack.push(n);
    }
    
    public void pop() {
        this.stack.pop();
    }
    
    public int top() {
        return this.stack.peek().data;
    }
    
    public int getMin() {
        return this.stack.peek().min;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */