/*
 * =====================================================================================
 *
 *       Filename:  CamelCase.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/04/2021 23:50:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (mn), mehner@fh-swf.de
 *        Company:  FH Südwestfalen, Iserlohn
 *
 * =====================================================================================
 */

#include<iostream>
#include<ctype.h>
using namespace std;

// void separator(char* str){

// 	for(int i = 0 ;str[i]!='\0';i++){
// 		if (str[i]>=65&&str[i]<=90){
// 			cout << endl;
// 		}
// 		cout<<str[i];
// 	}

// }

int main(){

	char arr[] = "abc";
	for(int i= 0;arr[i]!='\0';i++){
		cout << arr[i];
		if(arr[i+1]!='\0'){
			cout<<arr[i]-arr[i+1];
		}
	}
	return 0;
}

	












