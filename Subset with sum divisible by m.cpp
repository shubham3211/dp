#include <iostream>
using namespace std;
bool subsetDivRecur(int *arr,int length,int m,int sum){
	if(length<=0){
		return false;
	}

	if(sum%m == 0){
		return true;
	}

	return subsetDivRecur(arr,length-1,m,sum) || subsetDivRecur(arr,length-1,m,sum+arr[length]);
}

bool subsetDivDp(int *arr, int length,int m){

	bool dp[100] ={0},temp[100]={0};

	if(length>m){
		return true;
	}

	for(int i=0;i<length;i++){

		if(dp[0]==true){
			return true;
		}

		for(int j=0;j<m;j++){

			if(dp[j]){

				temp[(j+arr[i])%m] = true;

			}

		}

		dp[arr[i]%m] = true;

		for(int k=0;k<m;k++){
			if(temp[k]){
				dp[k]=true;
			}
		}

	}

	return dp[0];

}
int main(){
	int arr[100],length,m;
	bool ans;
	cout<<"Enter the length";
	cin>>length;
	cout<<"Enter the array";
	for(int i=0;i<length;i++){
		cin>>arr[i];
	}
	cout<<"Enter the value of no to divide";
	cin>>m;
	// ans=subsetDivRecur(arr,length-2,m,arr[length-1]);
	// if(ans){
	// 	cout<<"Present";
	// }else{
	// 	cout<<"Not Present";
	// }

  ans = subsetDivDp(arr,length,m);
	if(ans){
		cout<<"Present";
	}else{
		cout<<"Not Present";
	}
}