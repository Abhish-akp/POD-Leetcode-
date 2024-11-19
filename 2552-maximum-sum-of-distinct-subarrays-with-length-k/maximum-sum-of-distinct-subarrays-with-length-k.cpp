class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long int max_sum=0,sum=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            sum+=nums[i];
            if(i>=k){
                sum-=nums[i-k];
                mp[nums[i-k]]--;
                if(mp[nums[i-k]]==0){
                    mp.erase(nums[i-k]);
                }
            }
            if(i>=k-1 && k==mp.size())
                max_sum=max(sum,max_sum);
        }
    return max_sum;
    }
};