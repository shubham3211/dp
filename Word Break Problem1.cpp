#include <iostream>
#include <string>
using namespace std;
string str[100];
int noOfWords;
void enterWords(){
	for(int i=0;i<noOfWords;i++){
		cin>>str[i];
	}
}
bool searchDictionary(string findString){
	for(int i=0;i<noOfWords;i++){
		if(findString==str[i]){
			return true;
		}
	}
	return false;
}
bool substringCheck(string findString){
	bool stringCheck[1000][1000];
	int size=findString.length();
	for(int l=0;l<size;l++){
		for(int j=0;j<size-l;j++){
			cout<<findString.substr(j,j+l+1)<<endl;
			if(searchDictionary(findString.substr(j,l+1))){
				stringCheck[j][j+l]=true;
			} else{
				for(int k=j;k+1<=j+l;k++){
					if(stringCheck[j][k]&&stringCheck[k+1][j+l]){
						stringCheck[j][j+l]=true;
					}
				}
			}
		}
	}
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<stringCheck[i][j]<<" ";
		}
		cout<<endl;
	}
	return stringCheck[0][size-1];
}
int main(){
	string findString;
	bool ans;
	cout<<"Enter the words";
	cin>>noOfWords;
	enterWords();
	cout<<"Enter'the string to search";
	cin>>findString;
	ans=substringCheck(findString);
	if(ans){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
}