class Solution {
public:
    long long shortestSubarray(vector<int>& nums, long long k) {
        deque<pair<long,long>>dq;
        int n = nums.size();
        long long shortest=INT_MAX;
        long long sum=0;
        for(long long i=0;i<n;++i){
            sum+= nums[i];
            if(sum>=k) 
                shortest=min(shortest,(i+1));

            pair<long long,long> curr{INT_MIN,INT_MIN};
            while(!dq.empty() && (sum-dq.front().second >= k)){
                curr=dq.front();
                dq.pop_front();
            }

            if(curr.second!=INT_MIN){
                shortest = min(shortest,(i- curr.first));
            }
            while(!dq.empty() && sum<=dq.back().second){
                dq.pop_back();
            }
            dq.push_back({i,sum});
        }
        return shortest==INT_MAX ? -1 : shortest;
    }
};