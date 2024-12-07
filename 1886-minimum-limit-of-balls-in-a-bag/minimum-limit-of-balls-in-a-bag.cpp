class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int result = INT_MAX;
        while(low<=high){
            int mid= low + (high - low)/2;
            if(check(mid,maxOperations,nums)){
                result = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return result;
    }
private: 
    bool check(int mid,int operation, vector<int>&nums){
        int element = 0;
        for (auto it : nums){
            element += ceil((double)(it - mid)/mid);
        }
        return element<=operation;
    }
};