#include <iostream>
using namespace std;
bool subsetSum(int subset[],int length,int sum){

	if(sum == 0){
		return true;
	}
	if(length <0 || sum<0){
		return false;
	}

	return subsetSum(subset,length-1,sum-subset[length-1])||subsetSum(subset,length-1,sum);
}

bool subsetSumDp(int subset[],int length,int sum){
	bool subsetStore[100][100];
	for(int i=0;i<sum+1;i++){
		if(subset[0]==i){
			subsetStore[0][i] = true;
		} else {
			subsetStore[0][i] = false;
		}
	}

	for(int i=0;i<length;i++){
		subsetStore[i][0] = true;
	}

	for(int i=1;i<length;i++){
		for(int j=1;j<=sum;j++){
			subsetStore[i][j] = subsetStore[i-1][j]||subsetStore[i-1][j-subset[i]];
		}
	}

	return subsetStore[length-1][sum];
}

int main(){
   int subset[100],length,sum;
   bool sumPresent;
   cout<<"Enter the sum"<<endl;
   cin>>sum;
   cout<<"Enter the length"<<endl;
   cin>>length;
   cout<<"Enter the subset"<<endl;
   for(int i=0;i<length;i++){
   	cin>>subset[i];
   }
   sumPresent = subsetSumDp(subset,length,sum);
   if(sumPresent){
   	cout<<"Present";
   } else {
   	 cout<<"Not Present"; 	
   }
}