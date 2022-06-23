class Solution {
    public int scheduleCourse(int[][] courses) {
        // Sort the array according to its deadline
        Arrays.sort(courses, (a,b) -> {
            return a[1] - b[1];
        });
        
        // Build a Min-Heap
        PriorityQueue<Integer> heap = new PriorityQueue<>((a,b) -> {
            return b - a;
        });
        
        int current = 0;
        
        for(int[] c : courses) {
            if(current + c[0] <= c[1]){ // If applicable
                heap.add(c[0]);
                current += c[0];
            }
            else { // If not applicable
                if(!heap.isEmpty()) {
                    if(c[0] < heap.peek()){ // If this course is not the longest course
                        // Remove the longest course and take this course
                        current -= heap.peek();
                        heap.remove(); 
                        heap.add(c[0]);
                        current += c[0];  
                    }
                }
            }
        }
        return heap.size();
    }
}