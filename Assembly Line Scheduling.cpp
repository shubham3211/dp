#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
// typedef INT_MAX maximum;
int minJumps(int *jumps,int length){
	int dp[100];
	for(int i=0 ;i<=length;i++){
		dp[i] = INT_MAX;
	}
	dp[1] = 0;
	for(int i=1;i<length;i++){
		for(int j=i+1 ;j<=jumps[i]+i;j++){
			dp[j] = min(dp[j],dp[i]+1);
		}
	}
	for(int i=1; i<=length ;i++)
		cout<<dp[i]<<" ";
	cout<<endl;
	return dp[length];
}
int main(){
	int length,jumps[100],ans;
	cout<<"Enter the length";
	cin>>length;
	for(int i=1 ;i<length; i++){
		cin>>jumps[i];
	}
	ans = minJumps(jumps,length);
	cout<<"minimum jumps needed is"<<ans;
} 