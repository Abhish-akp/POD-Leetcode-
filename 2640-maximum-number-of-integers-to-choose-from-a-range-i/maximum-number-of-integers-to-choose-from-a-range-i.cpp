class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int>s(banned.begin(),banned.end());
        int sum=0;
        int count=0;
        for(int i=1;i<=n;i++){
            if(s.count(i)==0){
                sum+=i;
                if(sum>maxSum){
                    return count;
                }
                ++count;
            }
        }
        return count;
    }
};

// class Solution {
// public:
//     int maxCount(vector<int>& banned, int n, int maxSum) {
//         int i=1;
//         long sum=0;
//         int count=0;
//         int index;
//         vector<int>::iterator it;
//         while(i<=n){
//             it = find(banned.begin(),banned.end(),i);
//             index = distance(banned.begin(),it);
//             cout<<index<<" "<<sum<<" ";
//             if(index>=banned.size()){
//                sum+=i;
//                ++count;
//             }
//             if(sum>maxSum){
//                 return count;
//             }
//             i++;
//         }
//         return count;
//     }
// };