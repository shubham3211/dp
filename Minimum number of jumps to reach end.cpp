#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
// // typedef INT_MAX maximum;
// int minJumps(int *jumps,int length){
// 	int dp[100];
// 	for(int i=0 ;i<=length;i++){
// 		dp[i] = INT_MAX;
// 	}
// 	dp[1] = 0;
// 	for(int i=1;i<length;i++){
// 		for(int j=i+1 ;j<=jumps[i]+i;j++){
// 			dp[j] = min(dp[j],dp[i]+1);
// 		}
// 	}
// 	for(int i=1; i<=length ;i++)
// 		cout<<dp[i]<<" ";
// 	cout<<endl;
// 	return dp[length];
// }
// int main(){
// 	int length,jumps[100],ans;
// 	cout<<"Enter the length";
// 	cin>>length;
// 	for(int i=1 ;i<length; i++){
// 		cin>>jumps[i];
// 	}
// 	ans = minJumps(jumps,length);
// 	cout<<"minimum jumps needed is"<<ans;
// } 
// #include <stdio.h>
// #include <iostream>
// #include <limits.h>

int min(int x, int y) { return (x < y)? x: y; }

// Returns minimum number of jumps to reach arr[n-1] from arr[0]
int minJumps(int arr[], int n)
{
	int *jumps = new int[n]; // jumps[n-1] will hold the result
	int i, j;

	if (n == 0 || arr[0] == 0)
		return INT_MAX;

	jumps[0] = 0;

	// Find the minimum number of jumps to reach arr[i]
	// from arr[0], and assign this value to jumps[i]
	for (i = 1; i < n; i++)
	{
		jumps[i] = INT_MAX;
		for (j = 0; j < i; j++)
		{
			if (i <= j + arr[j] && jumps[j] != INT_MAX)
			{
				jumps[i] = min(jumps[i], jumps[j] + 1);
				break;
			}
		}
	}
	return jumps[n-1];
}

// int minJumps1(int jumps[],int size){
// 	int currentDest = jumps[1],maxDest = jumps[1],jmp=0;
// 	for(int i=1 ; i<=size ; i++){
// 		if(currentDest == i){
// 			currentDest = maxDest;
// 			jmp++;
// 		}
// 		if(jumps[i]+i>maxDest){
// 			maxDest = jumps[i]+i;
// 			if(maxDest > size){
// 				maxDest = size;
// 			}
// 		}
// 		currentDest++;
// 	}
// 	return jmp;
// }

// Returns minimum number of jumps to reach arr[n-1] from arr[0]
int minJumps1(int arr[], int n)
{
     
    // The number of jumps needed to reach the starting index is 0
    if (n <= 1)
        return 0;
 
    // Return -1 if not possible to jump
    if (arr[0] == 0)
        return -1;
 
    // initialization
    int maxReach = arr[0];  // stores all time the maximal reachable index in the array.
    int step = arr[0];      // stores the amount of steps we can still take
    int jump = 1;//stores the amount of jumps necessary to reach that maximal reachable position.
 
    // Start traversing array
    int i=1;
    for (i = 1; i < n; i++)
    {
        // Check if we have reached the end of the array
        if (i == n-1)
            return jump;
 
        // updating maxReach
        maxReach = max(maxReach, i+arr[i]);
 
        // we use a step to get to the current index
        step--;
 
        // If no further steps left
        if (step == 0)
        {
            // we must have used a jump
            jump++;
 
            // Check if the current index/position or lesser index
            // is the maximum reach point from the previous indexes
            if(i >= maxReach)
                return -1;
 
            // re-initialize the steps to the amount
            // of steps to reach maxReach from position i.
            step = maxReach - i;
        }
    }
 
    return -1;
}

// Driver program to test above function
int main(){
	int length,jumps[100],ans;
	cout<<"Enter the length";
	cin>>length;
	for(int i=1 ;i<=length; i++){
		cin>>jumps[i];
	}
	ans = minJumps1(jumps,length);
	cout<<"minimum jumps needed is"<<ans;
} 
