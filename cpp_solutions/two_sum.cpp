#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> mymap;
        
       

        for (int i = 0; i < nums.size(); i++) {
            
            unordered_map<int,int>::iterator it = mymap.find(nums[i]);
            if ( it == mymap.end()) {
               
                mymap.insert ( pair<int,int> (target - nums[i],i));

            } else {
                
                res.push_back(it->second);
                res.push_back(i);
                return res;
            }


        }
        
        return res;
        
    }
};
