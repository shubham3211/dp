#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>
using namespace std;
struct dimensions{
	int height;
	int width;
	int length;
};
int findArea(dimensions box){
	int ans=0;
	ans=max(ans,box.height*box.width);
	ans=max(ans,box.length*box.width);
	ans=max(ans,box.length*box.height);
	return ans;
}
bool myComp(dimensions box1,dimensions box2){
	int area1=0,area2=0;
	area1=findArea(box1);
	area2=findArea(box2);
	if(area1>area2){
		return true;
	} else{
		return false;
	}
}
bool findGreater(int l1,int w1,int l2,int w2){
	if(l1<l2&&w1<w2){
		return true;
	} else if(l1<l2&&w1<w2){
		return true;
	}
	return false;
}
int maxHeight(dimensions *arr,int pos,int stackHeight,int length,int width,int n){
	if(pos==n){
		return stackHeight;
	}
	int area1,area2,area3,ans=0,boxHeight,boxWidth,boxLength;
	// area1=arr[pos].height*arr[pos].width;
	// area2=arr[pos].height*arr[pos].length;
	// area3=arr[pos].width*arr[pos].length;
	boxHeight=arr[pos].height;
	boxLength=arr[pos].length;
	boxWidth=arr[pos].width;
	ans=maxHeight(arr,pos+1,stackHeight,length,width,n);
	if(findGreater(boxHeight,boxWidth,length,width)){
		ans=max(ans,maxHeight(arr,pos,stackHeight+boxLength,boxHeight,boxWidth,n));
	}
	if(findGreater(boxHeight,boxLength,length,width)){
		ans=max(ans,maxHeight(arr,pos,stackHeight+boxWidth,boxHeight,boxLength,n));
	}
	if(findGreater(boxWidth,boxLength,length,width)){
		ans=max(ans,maxHeight(arr,pos,stackHeight+boxHeight,boxWidth,boxLength,n));
	}
	return ans;
}
// int findMaxHeight(int n,dimensions *arr){
// 	int ans=0;
// 	ans=maxHeight(arr,0,0,INT_MAX,n);
// 	return ans;
// }
int main(){
	int n,h,l,w,ans=0;
	dimensions arr[100];
	cout<<"Enter the number of boxex";
	cin>>n;
	cout<<"Enter the height width and length";
	for(int i=0;i<n;i++){
		cin>>arr[i].height>>arr[i].width>>arr[i].length;
	}
	sort(arr,arr+n,myComp);
	// for(int i=0;i<n;i++){
	// 	cout<<arr[i].height<<" "<<arr[i].length<<" "<<arr[i].width<<endl;
	// }
	ans=maxHeight(arr,0,0,INT_MAX,INT_MAX,n);
	cout<<ans;
}