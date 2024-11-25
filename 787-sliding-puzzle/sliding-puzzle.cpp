class Solution1 {
public:
    // int slidingPuzzle(vector<vector<int>>& board) {
        // int n=board.size();
        // int m=board[0].size();
        // int flag=0;
        // int posx=-1,posy=-1;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(board[i][j]==0){
        //             flag=1;
        //             posx=i,posy=j;
        //             break;
        //         }
        //     }
        //     if(flag==1){
        //         break;
        //     }
        // }
        // if(posx==-1 && posy==-1){
        //     return -1;
        // }
        // int correctpos[n][m];
        // int x=1;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         correctpos[i][j]=x++;
        //     }
        // }
        // correctpos[n-1][m-1]=0;

};

vector<vector<char>> adj = {{1, 3}, {0, 2, 4}, {1, 5},
                            {0, 4}, {1, 3, 5}, {2, 4}};
int shift[6]={15, 12, 9, 6, 3, 0};
using info=pair<int, char>;
class Solution {
public:
    static int slidingPuzzle(vector<vector<int>>& board) {
        int target = 0123450;// octal
        int start= 0;
        char pos0=-1;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++){
                int index=i*3+j;
                start+= (board[i][j]<<shift[index]);
                if (board[i][j]==0) pos0=index;
            }
        if (start == target)
            return 0;
        const int N=0543211;// octal
        bitset<N> viz;
        queue<info> q;
        q.emplace(start, pos0);
       
        for (int move= 0; !q.empty();  move++) {
            int qz = q.size();
            for (int i = 0; i < qz; i++) {
                auto [t, p0] = q.front();
            //    cout<<oct<<t<<" p0="<<int(p0)<<" move="<<move<<endl;
                q.pop();
                if (t == target)
                        return move;
                for (char p : adj[p0]) {
                    int s = t, B=shift[p];
                    int x=((s>>B)&7);
                    s+=-(x<<B)+(x<<shift[p0]);
                    
                    if (viz[s]==1)
                        continue;
                    q.emplace(s, p);
                    viz[s]=1;
                }
            }
        }
        return -1;
    }
};