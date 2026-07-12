class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<Integer> stack = new Stack<>();
        int maxArea = 0;

        //Traverse all bars (including one extra imaginary bar of height of 0)
        for(int i = 0; i<= heights.length; i++){
            //Height of the imaginary bar is 0 to empty the stack at the end
            int currHeight = (i == heights.length) ? 0 : heights[i];

            //Current bar is smaller, so calculate area for taller bars
            while(!stack.isEmpty() && currHeight <heights[stack.peek()]){
                //Height of the rectangle
                int height = heights[stack.pop()];

                //if stack becomes mt, rectangle extends from the index 0
                int leftBoundary = stack.isEmpty()? -1 : stack.peek();

                //Width = right boundary - left boudnay -1
                int width = i - leftBoundary -1;

                //Update maximum rectangle found so far
                maxArea = Math.max(maxArea, height *width);
            }
            //Store current bar's index for the future calc
            stack.push(i);
        }
        return maxArea;
    }
}

/*

Create an empty stack.
Traverse all bars.
While the current bar is smaller than the top of the stack:
Pop the taller bar.
Calculate its height.
Find its width.
Update the maximum area.
Push the current index.
After traversal, pop any remaining bars and calculate their areas.
Return the maximum area.
*/
