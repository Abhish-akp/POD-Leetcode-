class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long result = 0;
        sort(nums.begin(),nums.end());

        for (int i = 0; i < nums.size() - 1; i++) {
            auto high=upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
            auto low=lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            result += (high - low);
        }
        return result;
    }
};

// class Solution {
// public:
//     long long countFairPairs(vector<int>& nums, int lower, int upper) {
//         int pair=0;
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 if((nums[i]+nums[j])<=upper && (nums[i]+nums[j])>=lower && i<j){
//                     pair++;
//                 }
//             }
//         }
//         return pair;
//     }
// };