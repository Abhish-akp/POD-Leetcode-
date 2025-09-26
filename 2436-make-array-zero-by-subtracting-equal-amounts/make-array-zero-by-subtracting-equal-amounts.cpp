class Solution {
public:
    int non_zero(vector<int>nums){
        int z=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<z && nums[i]!=0){
                z=nums[i];
            }
        }
        return z;
    }
    int minimumOperations(vector<int>& nums) {
        int n= nums.size();
        int count=0;
        while(1){
            int num = non_zero(nums);
            if(num==INT_MAX) break;
            for(int i=0;i<n;i++){
                if(nums[i]!=0)
                    nums[i]=nums[i]-num;
            }
            count++;
        }
        return count;
    }
};