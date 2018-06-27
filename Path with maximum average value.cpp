#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int print_avg(int arr[][100],int n,int x,int y,int length,int sum){
	int avg1=0,avg2=0;
	if(x>=n||y>=n){
		return 0;
	}
	if(x==n-1&&y==n-1){
		return sum/length;
	}
	avg1=print_avg(arr,n,x+1,y,length+1,sum+arr[x][y]);
	avg2=print_avg(arr,n,x,y+1,length+1,sum+arr[x][y]);
	return max(avg1,avg2);
}
float print_avg_Dp(int arr[][100],int n){
	float dp[100][100]={0};
	dp[0][0]=arr[0][0];
	for(int i=1;i<n;i++){
		dp[0][i]=dp[0][i-1]+arr[0][i];
		dp[i][0]=dp[i-1][0]+arr[i][0];
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			dp[i][j]=max(dp[i-1][j],dp[i][j-1])+arr[i][j];
		}
	}
	return dp[n-1][n-1]/(2*n-1);
}
int main(){
	int arr[100][100],n;
	float ans;
	cout<<"Enter the value of n";
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	ans=print_avg_Dp(arr,n);
	cout<<ans;
}