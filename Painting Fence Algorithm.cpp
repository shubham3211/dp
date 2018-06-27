#include <iostream>
using namespace std;
// int noOfWays(int n,int k,int times){
// 	if(n==0){
// 		return 1;
// 	}
// 	int repeat = 0,noRepeat = 0;
// 	for(int i=1;i<=k;i++){
// 		if(times!=0){
// 			repeat += noOfWays(n-1,k,times-1);
// 		}
// 		for(int j=1;j<=k;j++){
// 			if(j!=i){
// 				noRepeat += noOfWays(n-1,k,2);
// 			}
// 		}
// 	}

// 	return repeat + noRepeat;
// }
int noOfWays(int fence ,int paint){
	int dp[100] = {0};
	dp[1] = paint;
	for(int i=2;i<=fence;i++){
		dp[i] = (dp[i-1]+dp[i-2])*(paint-1);
	}
	return dp[fence-1] + dp[fence];	
}
int main(){
	int n,k,ans;
	cout<<"Enter no of fence";
	cin>>n;
	cout<<"Enter no of colors";
	cin>>k;
	ans = noOfWays(n,k);
	cout<<ans;
}