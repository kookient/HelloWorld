#include <iostream>
#include <algorithm>
using namespace std;

int positiveDif(int a , int b){
	return a>=b?a-b:b-a;
}

bool comp(const int& a, const int &b){
	return a<b?true:false;
}

int main(){
	int n,diskHead=0,totalTracks=0,brkPoint=0, maxSizeOfDisk=-1;
	int elems[100]={};
	
	cout<<"\nEnter number of locations : ";	
	cin>>n;
	cout<<"\nEnter position of head : ";
	cin>>diskHead;
	cout<<"\nEnter maximum size of disk : ";
	cin>>maxSizeOfDisk;
	cout<<"\nEnter elements of Disk Queue : \n";
	for(int i=0;i<n;i++){
		cout<<"Element "<<i<<" : ";
		cin>>elems[i];
	}

	sort(elems,elems+n,comp);
	for(int i=0;i<n;i++){
		if(diskHead < elems[i]){
			brkPoint=i-1;
			break;
		}
	}
	cout<<"\nOrder : "<<diskHead<<"->";
	// Travel left
	for(int i=brkPoint;i>=0;i--){
		totalTracks+=positiveDif(diskHead,elems[i]);
		diskHead=elems[i];
		cout<<elems[i]<<"->";
	}
	
	// Move to 0
	totalTracks+=diskHead;
	diskHead=0;
	cout<<"0->";

	// Don't need to add to total tracks when jumping to the end of disk
	diskHead=maxSizeOfDisk-1;
	cout<<maxSizeOfDisk-1<<"->";

	// Travel right
	for(int i=n-1;i>-brkPoint+1;i--){
		totalTracks+=positiveDif(diskHead,elems[i]);
		diskHead=elems[i];
		cout<<elems[i]<<"->";
	}

	cout<<"\nAnswer : "<<totalTracks<<"\n";
	return 0;
}