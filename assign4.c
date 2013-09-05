/* * * * * * * * * * * * * * * * * * * * *
 * Frederic Marchand
 * ID#100817579
 * Comp2003a4 
 *
 * This is the C programming part of 
 * the assignment. The (assembly) convert 
 * function is called from the main 
 * function in this c source file.
 *
 * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <string.h>

extern int convert(char*, int count);//assembly function
int checkDigit(char);
int getValue(char);
int getDecimal(char*);

int main(){
	char input[20];//input string
	unsigned int output = 0;//output

	printf("\nInput a hex digit: ");//message for input of hex string
	scanf("%s", input);//store the string in input

	if(strlen(input) > 7)//if the lenght is greater than 7 then its not valid for a 32 bit register
		printf("\nThe value you inputted is too large, program is terminating...\n");
	else{//otherwise
		output = convert(input, strlen(input));//call the assembly function
		if(output == -1){//if it returns -1 the characters were not valid hex digits
			printf("\nThe value inputted was not a valid hexadecimal number\n\nTerminating...\n\n");
		}
		else{//otherwise print the decimal value
			printf("\nThis is the decimal value of the hexadecimal number inputted: %d\n\n", output);	
		}
	}

	return 0;
}

//this function is called by the assembly portion of the program
int checkDigit(char digit){
	int flag = 1;
	if((digit=='A') || (digit=='B') || (digit=='C') || (digit=='D') || (digit=='E') || (digit=='F') ||  (digit=='1') || (digit=='2') || (digit=='3') ||
	  (digit=='4') || (digit=='5') || (digit=='6') || (digit=='7') || (digit=='8') || (digit=='9') || (digit=='0'))
		flag = 0;
	return flag;
}









//this function is called by the assembly portion of the program
int getValue(char input){
	int ret=0;
	if (input=='A'){
		ret = 10;
	}
	if (input=='B'){
		ret = 11;
	}
	if (input=='C'){
		ret = 12;
	} 
	if (input=='D'){
		ret = 13;
	}
	if (input=='E'){
		ret = 14;
	}
	if (input=='F'){
		ret = 15;
	}
	if (input=='1'){
		ret = 1;
	}
	if (input=='2'){
		ret = 2;
	}
	if (input=='3'){
		ret = 3;
	}
	if (input=='4'){
		ret = 4;
	}
	if (input=='5'){
		ret = 5;
	} 
	if (input=='6'){
		ret = 6;
	} 
	if (input=='7'){
		ret = 7;
	}
	if (input=='8'){
		ret = 8;
	}
	if (input=='9'){
		ret = 9;
	}
	
	return ret;
}

//this function is called by the assembly portion of the program
int getDecimal(char* str){
	int num;
	int i, j;
	int ret=0;
	int curr=0;
	int stringlength = strlen(str);
	for(i=0; i<strlen(str); i++){
		num = 1;
		curr = getValue(str[i]);
		for(j=0; j<stringlength-1; j++){
			num *= 16;
		}
		ret += curr*num;
		stringlength--;
	}
	return ret;
}
