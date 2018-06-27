#include <iostream>
using namespace std;
int Newman_Shanks_Williams(int n){
	if(n == 0 || n == 1){
		return 1;
	}
	return 2 * 	Newman_Shanks_Williams(n-1) + Newman_Shanks_Williams(n-2);
}

int Newman_Shanks_WilliamsDp(int n){
	int dp[100] = {0};
	dp[0] = 1;
	dp[1] = 1;
	for(int i=2;i<=n;i++){
		dp[i] = 2*dp[i-1] + dp[i-2];
	}	
	return dp[n];
}

int main(){
	int n,ans;
	cout<<"Enter the value of n";
	cin>>n;
	ans = Newman_Shanks_WilliamsDp(n);
	cout<<ans;
}