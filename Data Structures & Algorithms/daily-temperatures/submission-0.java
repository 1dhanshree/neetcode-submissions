class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int[] answer = new int[temperatures.length];
        Stack<Integer> stack = new Stack<>();

        //Traverse each day's temp
        for(int i = 0; i< temperatures.length; i++){
            //Current day is warmer than the previous unresolved days
            while(!stack.isEmpty() && temperatures[i] > temperatures[stack.peek()]){
                //Get the day waiting for a warmer temp
                int prevDay = stack.pop();

                //Number of days waited
                answer[prevDay] = i- prevDay;
            }
            //Curr day's ans is not known yet
            //save it's index for future comparison
            stack.push(i);
        }
        //Unresolved days automatically remain 0
        return answer;
    }
}

/*Create an answer array initialized with 0s.
Create a stack to store indices.
Traverse the temperatures array.
While the current temperature is warmer than the temperature at the top index of the stack:
Pop the previous index.
Calculate the waiting days.
Store it in the answer array.
Push the current index onto the stack.
Remaining indices have no warmer day, so they stay 0.*/