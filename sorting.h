#include <iomanip>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include "queue.h"
using namespace std;

void bubbleSort(int a[], int n){
	int i,j;
	int *d;
	int temp;
	d = a;
	int sorted;
	for (j = 1; j <= n-1; j++) {
		sorted = 0;
		for (i = 0; i < n-j; i++) {
			if(a[i] > a[i+1]){
				temp = *(d+i);
				*(d+i) = *(d+i+1);
				*(d+i+1) = temp;
				sorted = 1;
			}
		}
		if(sorted == 0)
			break;
	}
	cout<<endl;
}

//String to sort to attack.
void RanArrayGen(int c[], int n){
	int i;
	srand((int)time(0));
	cout<<"Array: ";
	for (i=0; i<n; i++){
		c[i] = rand()%35+11;
		cout<<c[i]<<" ";
	}
	cout<<endl;
}

//String to Input to Compare
int ArrayGen(int p[], int n){
	int i, a;
	for(i=0; i<n; i++){
		cout<<"Please Enter Digit Number: "<<i<<endl;
		cin>>a;
    if (a == p[i]){
      cout<<"Correct!"<<endl;
    }
    else{
      cout<<"Wrong!"<<endl;
      return 0;
    }
	}
  cout<<"Nice!"<<endl;
  return 1;
}