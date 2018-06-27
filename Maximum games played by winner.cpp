#include <iostream>
using namespace std;
int max_games(int n){
	int dp[100]={0},i;
	dp[1]=2;
	dp[0]=1;
	cout<<dp[0]<<" "<<dp[1]<<" "<<endl;
	for(i=2;dp[i-1]<=n;i++){
		dp[i]=dp[i-1]+dp[i-2];
		cout<<dp[i]<<" i is"<<i<<endl;	
	}
	cout<<endl;
	return i-2;	
}
int main(){
	int n,ans=0;
	cout<<"Enter the no of players";
	cin>>n;
	ans=max_games(n);
	cout<<ans;
}