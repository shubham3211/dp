#include <iostream>
using namespace std;
void initializeRow(bool subset[][100],int length,int *arr,int sum){
	subset[0][0] = true;
	for(int i=0;i<length;i++){
		for(int j=1;j<=sum;j++){
			if(arr[i]==j){
				subset[0][j] = true;
			}
		}
	}
}
bool subsetSum(int *arr,int lenght,int sum){
	bool subset[2][100] ={0};
	initializeRow(subset,lenght,arr,sum);
	for(int i=1;i<lenght;i++){
		for(int j=0;j<=sum;j++){
			if(j==0){
				subset[i%2][0]=true;
			}
			else if(arr[i]<=j){
				subset[i%2][j] = subset[(i+1)%2][j]||subset[(i+1)%2][j-arr[i]];
			}
		}
	}
	return subset[(lenght-1)%2][sum];
}
int main(){
	int arr[100],sum,length;
	bool ans;
	cout<<"Enter the sum";
	cin>>sum;
	cout<<"Enter the lenght";
	cin>>length;
	cout<<"Enter the array";
	for(int i=0;i<length;i++){
		cin>>arr[i];
	}
	ans=subsetSum(arr,length,sum);
	if(ans){
		cout<<"Sum is there";
	} else {
		cout<<"Sum is not present";
	}
}