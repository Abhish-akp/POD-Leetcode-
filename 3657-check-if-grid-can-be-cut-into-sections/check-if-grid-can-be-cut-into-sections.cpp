class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>>for_x;
        vector<pair<int,int>>for_y;

        int l=rectangles.size();
        int m=rectangles[0].size();


        for(int i=0;i<l;i++){
            for_x.push_back({rectangles[i][0],rectangles[i][2]});
        }

        for(int i=0;i<l;i++){
            for_y.push_back({rectangles[i][1],rectangles[i][3]});
        }

        sort(for_x.begin(),for_x.end());
        sort(for_y.begin(),for_y.end());


        int mx=for_y[0].second;
        int x1=0;
        int y1=0;

        for(int i=1;i<l;i++){
            if(for_y[i].first >= mx){
                mx = max(mx,for_y[i].second);
                x1++;
            }
            else{
                mx=max(mx,for_y[i].second);
            }
        }
        mx=for_x[0].second;

        for(int i=1;i<l;i++){
            if(for_x[i].first >= mx){
                mx=max(mx,for_x[i].second);
                y1++;
            }
            else{
                mx=max(mx,for_x[i].second);
            }

        }
        if(x1 >=2 || y1 >=2){
            return true;
        }
        return false;

    }
};