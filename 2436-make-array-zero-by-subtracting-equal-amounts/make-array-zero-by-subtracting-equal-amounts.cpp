class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> s;
        for (auto& num: nums) {
            if (num > 0) s.insert(num);
        }
        return s.size();
        
    }
};