#include <iostream>
#include <string>
using namespace std;
bool checkPalindrone(string str){
	int n=str.length()-1;
	for(int i=0;i<=n;i++){
		if(str[i]!=str[n-i]){
			return false;
		}
	}
	return true;
}
int longestPalindrone(string str,int i,int j){
	if(i==j){
		return 1;
	}
	if(str[i]==str[j]&&i+1==j){
		return 2;
	}
	if(str[i]==str[j]){
		return 2+longestPalindrone(str,i+1,j-1);
	}
	return max(longestPalindrone(str,i+1,j),longestPalindrone(str,i,j-1));	
}
int longestPalindroneDp(string str){
	int dp[700][700]={0},n=str.length();
	for(int i=0;i<n;i++){
		dp[i][i]=1;
	}
	for(int col=1;col<=n;col++){
		for(int i=0;i<n;i++){
			int j=i+col;
			if(str[i]==str[j]){
				dp[i][j]=dp[i+1][j-1]+2;
			}else{
				dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
			}
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[0][n-1];
}
int main(){
	string str;
	int ans=0;
	cout<<"Enter the string";
	cin>>str;
	ans=longestPalindroneDp(str)	;
	cout<<ans<<endl;
}