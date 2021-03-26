#include<iostream>
using namespace std;

int DAT[100] = {0};

int main(){
	int n;
	cin>>n;
	while(n--){
		int temp;
		cin>>temp;
		DAT[temp] = 1;
	}
	
	int s;
	cin>>s;
	if(DAT[s]){
	cout<<"present here";
	}
	else{
	cout<<"not here";
	}
	
	return 0;
}
	
