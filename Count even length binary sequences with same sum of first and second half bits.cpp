#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstring>
using namespace std;
int noOfSequenceRecur(int n,int diff){
	if(abs(diff)>n){
		return 0;
	}
	if(n==1&&diff==0){
		return 2;
	} else if(n==1&&abs(diff)==1){
		return 1;
	}
	return noOfSequenceRecur(n-1,diff-1) + 2*noOfSequenceRecur(n-1,diff) + noOfSequenceRecur(n-1,diff+1); 
}
int noOfSequenceDp(int n,int dp[][100],int diff){
	if(abs(diff)>n){
		return 0;
	}
	if(dp[n][n+diff]!=-1){
		return dp[n][n+diff];
	}
	if(n==1&&abs(diff)==0){
		return 2;
	} else if(n==1&&abs(diff)==1){
		return 1;
	}
	dp[n][n+diff]=noOfSequenceDp(n-1,dp,diff-1)+noOfSequenceDp(n-1,dp,diff)+noOfSequenceDp(n-1,dp,diff+1);
	return dp[n][n+diff];
}
int findSequence(int n){
	int dp[100][100];
	memset(dp,-1,sizeof(dp));
	return noOfSequenceDp(n,dp,0);
}
int main(){
	int n,ans;
	cout<<"Enter the value of n";
	cin>>n;
	ans=findSequence(n);
	cout<<ans;
}