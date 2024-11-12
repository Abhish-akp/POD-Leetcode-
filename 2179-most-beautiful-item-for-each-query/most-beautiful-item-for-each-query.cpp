class Solution {
public:
    int solve(vector<vector<int>>&v,int query){
        int s=0,e=v.size()-1;
        int ans=0;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(v[mid][0]<=query){
                ans=v[mid][1];
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n=queries.size();
        sort(items.begin(),items.end());
        for(int i=1;i<items.size();i++){
            items[i][1]=max(items[i-1][1],items[i][1]);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(solve(items,queries[i]));
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> maximumBeauty(vector<vector<int>>& items,vector<int>& queries) {
//         int m = queries.size();
//         vector<int> result;
//         sort(items.begin(), items.end());
//         result.push_back(items[0])
//         for(int j=1;j<m;j++){
//             int i = 0;
//             vector<int> temp;
//             while (queries[i] >= (int)items[i][0] && i < queries.size()) {
//                 temp.push_back(items[i][1]);
//                 i++;
//             }
//             int x = *max_element(temp.begin(), temp.end());
//             result.push_back(x);
//         }
//         return result;
//     }
// };