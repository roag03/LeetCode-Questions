class Solution {
public:
bool checkleft(vector<vector<int>>& mat ,int i, int j){
        if(mat[i][j]>=mat[i-1][j]) return true;
        return false; 
    }
    bool checkright(vector<vector<int>>& mat ,int i, int j){
        if(mat[i][j]>=mat[i+1][j]) return true;
        return false; 
    }
    bool checkup(vector<vector<int>>& mat ,int i, int j){
        if(mat[i][j]>=mat[i][j-1]) return true;
        return false;
    }
    bool checkbottom(vector<vector<int>>& mat ,int i, int j){
        if(mat[i][j]>=mat[i][j+1]) return true;
        return false;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
         std::ios_base::sync_with_stdio(false);
        std::cout.tie(nullptr);
        std::cin.tie(nullptr);
        int rows=mat.size(),cols=mat[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int currele=mat[i][j];
                bool cl,cr,cu,cd;
                if(i-1>=0){
                    cl=checkleft(mat,i,j);
                }
                else if(mat[i][j]>=-1) cl=true;
                else cl=false;
                
                if(i+1<rows){
                    cr=checkright(mat,i,j);
                }
                else if(mat[i][j]>=-1) cr=true;
                else cr=false;

                if(j-1>=0){
                    cu=checkup(mat,i,j);
                }
                else if(mat[i][j]>=-1) cu=true;
                else cu=false;

                if(j+1<cols){
                    cd=checkbottom(mat,i,j);
                }
                else if(mat[i][j]>=-1) cd=true;
                else cd=false;


                if(cl and cr and cu and cd) return {i,j};
            }
        }
        return {-1,-1};
    }
    
};
