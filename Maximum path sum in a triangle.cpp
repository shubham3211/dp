#include <iostream>
using namespace std;
int max_path(int arr[][100],int rows){
	int dp[100][100]={};
	for(int i=rows-1;i>0;i--){
		for(int j=0;j<i;j++){
			arr[i-1][j]+=min(arr[i][j],arr[i][j+1]);
		}
	}
	return arr[0][0];
}
int main(){
	int rows,arr[100][100],ans=0;
	cout<<"Enter the number of rows";
	cin>>rows;
	for(int i=0;i<rows;i++){
		for(int j=0;j<=i;j++){
			cin>>arr[i][j];
		}
	}
	ans=max_path(arr,rows);
	cout<<ans;
}