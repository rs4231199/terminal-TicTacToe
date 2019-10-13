#include <iostream>
using namespace std;

void enter(int *a, int data) {
	if(data==0)	cout<<"Enter a place number for '0':";
	else	cout<<"Enter a place number for 'x':";
	int x; cin>>x;
	while(a[x-1]!=-1 or x>9 or x<1) {
		cout<<"\nInvalid choice!!\nEnter again:";
		cin>>x;
	}
	a[x-1] = data;
	system("clear");
	for(int i=0; i<9; i++) {
		if(a[i] == -1) cout<<"| ";
		else if(a[i] == 0) cout<<"|0";
		else cout<<"|x";
		if(i==2 or i==5) cout<<"|"<<endl<<"-------"<<endl;
		if(i==8) cout<<"|"<<endl;
	}
}

int check(int *a, int data) {
	int rtrn = 0; //rtrn==0 for negative result and 1 for positive
	if(a[0]==a[1] and a[1]==a[2] and a[2]!=-1) rtrn=1;
	if(a[3]==a[4] and a[4]==a[5] and a[5]!=-1) rtrn=1;
	if(a[6]==a[7] and a[7]==a[8] and a[8]!=-1) rtrn=1;
	if(a[0]==a[3] and a[3]==a[6] and a[6]!=-1) rtrn=1;
	if(a[1]==a[4] and a[4]==a[7] and a[7]!=-1) rtrn=1;
	if(a[2]==a[5] and a[5]==a[8] and a[8]!=-1) rtrn=1;
	if(a[0]==a[4] and a[4]==a[8] and a[8]!=-1) rtrn=1;
	if(a[2]==a[4] and a[4]==a[6] and a[6]!=-1) rtrn=1;
	return rtrn;
}

int main () 
{
	system("clear");
	int a[9]={-1,-1,-1,-1,-1,-1,-1,-1,-1};
	for(int i=0; i<9; i++) {
		if(a[i] == -1) cout<<"| ";
		else if(a[i] == 0) cout<<"|0";
		else cout<<"|x";
		if(i==2 or i==5) cout<<"|"<<endl<<"-------"<<endl;
		if(i==8) cout<<"|"<<endl;
	}
	int turn = 0; //defining first move of zero
	for(int i=0; i<9; i++) {
		enter(a, turn);
		if(check(a,turn)) {
			if(turn == 0) cout<<"'0' wins!!\n";
			else 	cout<<"'x' wins!!\n"; 
			break;
		}
		turn = (turn==0?1:0);
	}
	return 0; 
} 
