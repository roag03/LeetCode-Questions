class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size() ;
       
        if(n < d){
          
            return -1 ;
        }

        return solveTabOptimise(jobDifficulty, d) ;
    }
private: 

    int solve(vector<int>& jd, int d, int index){
      
        if(d == 1){
            if(index >= jd.size()){
                return 0 ; 
            }
            else{
               
                int maxi = INT_MIN ;

                for (int i = index ; i < jd.size(); i++){
                    maxi = max(maxi, jd[i]) ;
                }
                return maxi ;
            }
        }

       

        int maxi = jd[index] ; 
        int rightIndex = jd.size() - d; 
        
        int result = INT_MAX ;

        for(int i = index ; i <= rightIndex; i++){
            maxi = max(maxi, jd[i]) ;
            int remaining = solve(jd, d-1, i+1) ; 
            result = min(result, maxi + remaining) ;
        }

        return result ; 
    }

    int solveMem(vector<int>& jd, int d, int index, vector<vector<int>>& dp){
        
        if(d == 1){
            if(index >= jd.size()){
                return 0 ; 
            }
            else{
               
                int maxi = INT_MIN ;

                for (int i = index ; i < jd.size(); i++){
                    maxi = max(maxi, jd[i]) ;
                }
                return maxi ;
            }
        }

      
        if(dp[d][index] != -1){
            return dp[d][index] ;
        }

        int maxi = jd[index] ; 
        int rightIndex = jd.size() - d; 
        
        int result = INT_MAX ;

        for(int i = index ; i <= rightIndex; i++){
           
            maxi = max(maxi, jd[i]) ;
            int remaining = solveMem(jd, d-1, i+1, dp) ;
            result = min(result, maxi + remaining) ;
        }

       
        return dp[d][index] = result ; 
    }

    int solveTab(vector<int>& jd, int d){
        int n = jd.size() ;
        vector<vector<int>> dp(d+1, vector<int>(n+1, 0)) ;

      
        dp[1][n] = 0 ; 
        int maxi = INT_MIN ; 
        
        for(int i = n-1 ; i >= 0; i--){
            maxi = max(maxi, jd[i]) ;
            dp[1][i] = maxi ; 
        }

        for(int dayRem = 2 ; dayRem <= d; dayRem++){
            for(int index = n-1 ; index >= 0 ; index--){
                int maxi = jd[index] ; 
                int rightIndex = jd.size() - dayRem; 

                int result = INT_MAX ;

                for(int i = index ; i <= rightIndex; i++){
                
                    maxi = max(maxi, jd[i]) ;
                    int remaining = dp[dayRem-1][i+1] ;
                    result = min(result, maxi + remaining) ;
                }

                dp[dayRem][index] = result ; 
            }
        }

        return dp[d][0] ; 
    }

    int solveTabOptimise(vector<int>& jd, int d){
        int n = jd.size() ;
        vector<int> prev(n+1, 0) ;
        vector<int> curr(n+1, 0) ;
        prev[n] = 0 ; 
        int maxi = INT_MIN ; 
        for(int i = n-1 ; i >= 0; i--){
            maxi = max(maxi, jd[i]) ;
            prev[i] = maxi ;
        }

        for(int dayRem = 2 ; dayRem <= d; dayRem++){
            for(int index = n-1 ; index >= 0 ; index--){
                int maxi = jd[index] ; 
                int rightIndex = jd.size() - dayRem; 

                int result = INT_MAX ;

                for(int i = index ; i <= rightIndex; i++){
                
                    maxi = max(maxi, jd[i]) ;
                    int remaining = prev[i+1] ;
                    result = min(result, maxi + remaining) ;
                }

                curr[index] = result ; 
            }
            prev = curr ;
        }

        return prev[0] ; 
    }
};