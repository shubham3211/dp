#include <iostream>
using namespace std;
int no_of_ways(int n,int m,int x){
	if(x==0&&n==0){
		return 1;
	}
	if(n<0||x<0){
		return 0;
	}
	int sum=0;
	for(int i=1;i<=m;i++){
		sum+=no_of_ways(n-1,m,x-i);
	}
	return sum;
}
int no_of_ways_dp(int n,int m,int x){
	int dp[1000][1000]={0};
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=x;j++){
			for(int k=1;k<=m&&k<=j;k++){
				dp[i][j]+=dp[i-1][j-k];
			}
		}
	}
	return dp[n][x];
}
int main(){
	int n,m,ans=0,x;
	cout<<"Enter no of dice";
	cin>>n;
	cout<<"Enter no of faces";
	cin>>m;
	cout<<"Enter the value to be obtained";
	cin>>x;
	ans=no_of_ways(n,m,x);
	cout<<ans;
}