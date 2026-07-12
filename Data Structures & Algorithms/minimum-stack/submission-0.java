class MinStack {

    //Stores all elements
    Stack<Integer> stack;
    //Stores the min value correspoinding to each element in the stack
    Stack<Integer> minStack;

    public MinStack() {
        stack = new Stack<>();
        minStack = new Stack<>();
    }
    
    public void push(int val) {
        //Push the value in the main stack
        stack.push(val);

        //first element is always the min
        if(minStack.isEmpty()){
            minStack.push(val);
        }else{
            //store the min value seen so far
            minStack.push(Math.min(val, minStack.peek()));
        }
    }
    
    public void pop() {
        //Remove the top element from both
        stack.pop();
        minStack.pop();
    }
    
    public int top() {
        //Return the latest inserted element
        return stack.peek();
    }
    
    public int getMin() {
        //top of minStack always store the curr Min
        return minStack.peek();
    }
}
