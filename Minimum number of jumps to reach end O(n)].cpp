#include <iostream>
#include <algorithm>
using namespace std;
int minJumps(int jumps[],int length){
	int steps=jumps[0],maxReach=jumps[0],jump=1;
	for(int i=1;i<length;i++){
		if(i==length-1){
			return jump;
		}
		steps--;
		maxReach=max(i+jumps[i],maxReach);
		if(steps==0){
			if(i>=maxReach){
				return -1;
			}
			steps=maxReach-i;
			jump++;
		}
	}
}
int main(){
	int length,jumps[100],ans;
	cout<<"Enter the length";
	cin>>length;
	for(int i=0;i<length;i++){
		cin>>jumps[i];
	}
	ans=minJumps(jumps,length);
	cout<<ans;
}