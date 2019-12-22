#include <iostream>
#include <windows.h>
#include <stdio.h>
using namespace std;
int i=0;
int main(){
	
	while( i <= 256){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
		cout << "Toni Mikitsch" << i << endl;
		i++;
	
	}
	getchar();
	return 0;
}

