class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
                    
        int res = 0;
        
        sort(nums.begin(), nums.end());
        int nums_size = nums.size();
        int closest = nums[0] + nums[1] + nums[2];
        for (int ia = 0; ia < nums_size-2; ++ia) {
            if (ia>0 && nums[ia-1]==nums[ia]) continue;
            int a = nums[ia];
            int low = ia+1;
            int high = nums_size-1;
            
            
            while (low < high) {
                int b = nums[low];
                int c = nums[high];
                if (a + b + c == target)
                    return target;
                
                uint32_t diff = abs(closest - target);
                uint32_t current_diff = abs(a + b + c - target);
                
                if (current_diff < diff) {
                    closest = a + b + c;
                }
                
                if (target < (a + b + c)) {
                    while(high>0 && nums[high]==nums[high-1]) high--;
                    --high;
                } else {
                     while(low<nums_size && nums[low]==nums[low+1]) low++;
                    ++low;
                }
                
                
                
            }
        }
        
        return closest;
    }
};
