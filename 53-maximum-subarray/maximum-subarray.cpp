class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=nums[0];
        if(nums.size()==1){
            return nums[0];
        }
        int maxi=nums[0];
        for(int i=1;i<nums.size();i++){
            maxi=max(nums[i],nums[i]+maxi);
            res=max(res,maxi);
        }
        return res;
    }
};