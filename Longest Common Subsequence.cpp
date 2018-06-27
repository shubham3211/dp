#include <iostream>
#include <string>
using namespace std;
int lcs(string str1,string str2,int n,int m){
	int ans=0;
	if(n==str1.length()||m==str2.length()){
		return ans;
	}
	if(str1[n]==str2[m]){
		ans = 1+lcs(str1,str2,n+1,m+1);
	} else{
		ans = max(lcs(str1,str2,n+1,m),lcs(str1,str2,n,m+1));
	}
	return ans;
}
int lcsDp(string str1,string str2){
	int dp[100][100]={0};
	for(int i=1;i<=str1.length();i++){
		for(int j=1;j<=str2.length();j++){
			if(str1[i-1]==str2[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[str1.length()][str2.length()];

}
int lcsSpace(string str1,string str2){
	int dp[2][100]={0};
	bool bi;
	for(int i=1;i<=str1.length();i++){
		for(int j=1;j<=str2.length();j++){
			bi=i&1;
			if(str1[i-1]==str2[j-1]){
				dp[bi][j]=dp[1-bi][j-1]+1;
			} else{
				dp[bi][j]=max(dp[1-bi][j],dp[bi][j-1]);
			}
		}
	}
	return dp[str1.length()%2][str2.length()];
}
int main(){
	int ans;
	string str1,str2;
	cout<<"Enter string 1";
	cin>>str1;
	cout<<"Enter string 2";
	cin>>str2;
	ans=lcsSpace(str1,str2);
	cout<<ans;
}