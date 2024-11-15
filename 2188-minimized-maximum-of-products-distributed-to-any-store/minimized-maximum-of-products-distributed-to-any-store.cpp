class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int beg=1;
        int last=*max_element(quantities.begin(),quantities.end());
        int mid;
        int minProduct=INT_MAX;
        while(beg<=last){
            mid=beg+(last-beg)/2;
            if(distributed(mid,n,quantities)){
                minProduct=min(minProduct,mid);
                last=mid-1;
            }
            else{
                beg=mid+1;
            }
        }
        return minProduct;
    }
private:
    bool distributed(int x,int n,vector<int>&quantities){
        int count=0;
        for(int i=0;i<quantities.size();i++){
            count+=ceil((double)quantities[i]/x);
        }
        return count<=n;
    }
};