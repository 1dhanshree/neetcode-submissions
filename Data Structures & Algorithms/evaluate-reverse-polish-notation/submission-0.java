class Solution {
    public int evalRPN(String[] tokens) {
        //empty stack 
        Stack<Integer> stack = new Stack<>();
        for(String t: tokens){
            //if token is a operator evaluate the expression further
            if(t.equals("+") || t.equals("-") || t.equals("*") || t.equals("/")){
                //second operand will be the first to pop
                int n2 = stack.pop();
                //first operand will be second to pop
                int n1 = stack.pop();

                //Perform operation accordin to operation
                if(t.equals("+")){
                    stack.push(n1 + n2);
                } else if(t.equals("-")){
                    stack.push(n1 - n2);
                } else if(t.equals("*")){
                    stack.push(n1 * n2);
                } else{
                    stack.push(n1 / n2);
                }
            }else{
                //if token is a number just push in hte stack but first parse to Integer
                stack.push(Integer.parseInt(t));
            }
        }
        //Finish answer is only left
        return stack.peek();
    }
}
