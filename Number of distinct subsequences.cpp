//User function template for C++

//User function template for C++

class Solution{
  public:	
    int mod=1e9 + 7;
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int n=s.size();
	    vector<int>dp(n+1,0);
	    dp[0]=1;         //  {}
	    unordered_map<char,int>mp;
	    for(int i=1;i<=n;i++){
	        int prev=-1;
	        if(mp.find(s[i-1])!=mp.end())prev=mp[s[i-1]];
	        int cur=(2*dp[i-1])%mod;
	        if(prev!=-1)cur=cur-dp[prev-1];
	        mp[s[i-1]]=i;
	        dp[i]=(cur+mod)%mod;
	        
	    }
	    
	    return dp[n]%mod;
	}
};
