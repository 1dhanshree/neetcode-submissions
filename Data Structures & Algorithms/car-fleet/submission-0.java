class Solution {
    public int carFleet(int target, int[] position, int[] speed) {
        int n = position.length;
        //Store each car's position and speed together
        int[][] cars = new int[n][2];
        for(int i = 0; i<n; i++){
            cars[i][0] = position[i];
            cars[i][1] = speed[i];
        }

        //sort cars based on their position (nearest to target comes last)
        Arrays.sort(cars, (a, b) -> a[0] - b[0]);
        Stack<Double> stack = new Stack<>();

        //Start from the car closest to the target
        for(int i = n-1; i >= 0; i--){
            //time taken by the current car to reach the target
            double time = (double) (target - cars[i][0]) / cars[i][1];

            //This car forms a new fleet
            if(stack.isEmpty() || time > stack.peek()){
                stack.push(time);
            }

            //If time <= stack.peek(), this car catches the fleet ahead
            //Do nothing because it becomes part of that fleet
        }

        return stack.size();
    }
}

/*
Pair each car's position and speed.
Sort cars by position (ascending).
Traverse from the last car (closest to target) to the first.
Calculate the time to reach the target.
If the current time is greater than the last fleet's time, create a new fleet.
Otherwise, it joins the existing fleet.
*/
