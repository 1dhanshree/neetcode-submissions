class Solution {
public:
    int trap(vector<int>& height) {
        int i =0;
        int j = height.size()-1;
        int marea = 0;
        int leftMax = 0, rightMax = 0;

        while(i<j){
            if(height[i] < height[j]){
                if (height[i] >= leftMax) leftMax = height[i];
                else marea += leftMax - height[i];
                i++;
            }else{
                if (height[j] >= rightMax) rightMax = height[j];
                else marea += rightMax - height[j];
                j--;
            }
        }
        return marea;
    }
};
