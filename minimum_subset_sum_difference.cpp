// for non-negative :(
int knap(vector<int>& v, int n, int w, vector<vector<int>>& dp){
        if(n==0 && w!=0) return 0;
        if(w==0) return 1;

        if(dp[n][w]!=-1) return dp[n][w];
        
        if(v[n-1]<=w){
            return dp[n][w]= knap(v,n-1,w-v[n-1],dp) || knap(v,n-1,w,dp);
        }
        else {
            return dp[n][w]= knap(v,n-1,w,dp);
        }
    }
    
int minimumDifference(vector<int>& nums) {
    int s=0;
    for(auto i:nums) s+=i;
    
    vector<int>t;
    for(int i=1;i<=s;i++){
        vector<vector<int>>dp;
        dp.resize(nums.size()+1, vector<int>(i+1,-1));
        if(knap(nums,nums.size(),i,dp) ==1){
            t.push_back(i);
            //cout<<i<<" ";
        }
    }
    int m=INT_MAX;
    for(int i=0;i<t.size()-1;i++){
        for(int j=0;j<t.size();j++){
            if(t[i]+t[j]==s){
                m=min(m,abs(t[i]-t[j]));
            }
        }
    }
    return m;
}
int Solution::solve(vector<int> &A) {
    if(A.size()==1) return A[0];
    return minimumDifference(A);
}
