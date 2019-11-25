#include<iostream>
using namespace std;
int main(){
	int var_a[5];
	int var_b[5];
	int i = 0;
	for(i=0;i<5;i++){
		cout << "var_a[" << i << "]";
		cin >> var_a[i];
	}
	for(i=0;i<5;i++){
		cout << "var_b[" << i << "]";
		cin >> var_b[i];
	}
	int j = 4;
	for(i=0;i<5;i++){
		cout << "var_a[" << i << "] + var_b[" << j << "] = " << var_a[i] + var_b[j] << endl;
		j--;
	}
	return 0;
}
