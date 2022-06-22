class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());

        for(int i = k; i > 1; i--){
            pq.pop();
        }
        
        return pq.top();
    }
};