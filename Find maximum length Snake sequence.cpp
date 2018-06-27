#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;
int row , col;
int maxLength(int arr[][100],int x,int y,int length){
	int max1=0,max2=0;
	if(x==row-1 && y==col-1){
		return length;
	}
	if(abs(arr[x+1][y]-arr[x][y])==1){
		max1=maxLength(arr,x+1,y,length+1);
	}
	if(abs(arr[x][y+1]-arr[x][y])==1){
		max2=maxLength(arr,x,y+1,length+1);
	}
	return max(max1,max2);
}

void printSnake(int dp[][100],int arr[][100],int maxLength,int max_col,int max_row){
	std::vector<int> v;
	while(maxLength>=0){
		if(dp[max_row][max_col]-dp[max_row-1][max_col]==1){
			v.push_back(arr[max_row][max_col]);
			max_row--;
		} else if(dp[max_row][max_col]-dp[max_row][max_col-1]==1){
			v.push_back(arr[max_row][max_col]);
			max_col--;
		}
		maxLength--;
	}
	v.push_back(arr[max_row][max_col]);

	for(vector<int>::iterator it=v.end()-1;it!=v.begin()-1;it--){
		cout<<*it<<" ";
	}
	cout<<endl;
}

int maxLengthDp(int arr[][100]){
	int dp[100][100]={0},max_len=0,max_row=0,max_col=0;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(i!=0&&abs(arr[i][j]-arr[i-1][j])==1){
				dp[i][j]=max(dp[i][j],dp[i-1][j]+1);
				if(max_len<dp[i][j]){
					max_len=dp[i][j];
					max_row=i,max_col=j;
				}
			}
			if(j!=0&&abs(arr[i][j]-arr[i][j-1])==1){
				dp[i][j]=max(dp[i][j],dp[i][j-1]+1);
				if(max_len<dp[i][j]){
					max_len=dp[i][j];
					max_row=i,max_col=j;
				}
			}	
		}
	}
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	printSnake(dp,arr,max_len,max_col,max_row);
	return max_len;
}

int main(){
	int arr[100][100],ans=0;
	cout<<"Enter the rows";
	cin>>row;
	cout<<"Enter the columns";
	cin>>col;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cin>>arr[i][j];
		}
	}
	ans = maxLengthDp(arr);
	cout<<ans;
}