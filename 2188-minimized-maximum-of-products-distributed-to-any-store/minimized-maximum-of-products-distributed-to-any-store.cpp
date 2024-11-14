class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low=1;
        int high=*max_element(quantities.begin(),quantities.end());
        int xount=INT_MAX;
        int mid;
        while(low<=high){
             mid=low+(high-low)/2;
            if(func(mid,n,quantities)){
                xount=min(mid,xount);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return xount;
    }
private:
    int func(int x,int n,vector<int>& quantities){
        int count=0;
        for(int i=0;i<quantities.size();i++){
            count+=ceil((double)quantities[i]/x);
        }
        return count<=n;
    }
};