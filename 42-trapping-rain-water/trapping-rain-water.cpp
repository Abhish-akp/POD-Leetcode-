class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>lf(n),rt(n);
        lf[0]=height[0],rt[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            lf[i]=max(lf[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            rt[i]=max(rt[i+1],height[i]);
        }
        int waters = 0;
        for(int i=1;i<n-1;i++){
          waters += min(lf[i],rt[i])-height[i];
        }
        return waters;
    }
};