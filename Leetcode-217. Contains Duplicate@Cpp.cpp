class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> myset;

        for(int num : nums) {
            if(myset.find(num) != myset.end()) {
                return true;
            }
            myset.insert(num);
        }

        return false;
    }
};