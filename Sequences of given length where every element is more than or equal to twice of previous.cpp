#include <iostream>
#include <math.h>
using namespace std;
int noOfSequence(int n,int m,int val){
	if(n==0){
		return 1;
	}
	int ans=0;
	while(val*pow(2,n-1)<=m){
		ans+=noOfSequence(n-1,m,val*2);
		val++;
	}
	return ans;
}
int noOfSequence2(int n,int m){
	if(n==0){
		return 1;
	}
	if(n>m){
		return 0;
	}
	return noOfSequence2(n-1,m/2)+noOfSequence2(n,m-1);
}
int noOfSequenceDp(int n,int m){
	int dp[100][100]={0};
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==1){
				dp[i][j]=j;
			} else{
				dp[i][j]=dp[i-1][j/2]+dp[i][j-1];	
			}
		}
	}
	return dp[n][m];
}
int main(){
	int n,m,ans;
	cout<<"Enter the value of n";
	cin>>n;
	cout<<"Enter the value of m";
	cin>>m;
	ans=noOfSequenceDp(n,m);
	cout<<ans;
}