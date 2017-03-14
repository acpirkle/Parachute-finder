/*
Program Name: HW3.c
Programmer: Andrew Pirkle
Class: CS3335
HW: 3
Date: 10/14/15
*/
#include <stdlib.h>
#include<math.h>
#include<stdio.h>
#define min 14
#define max 15
float GetCargo();
float GetChuteSize(int count);
float Computefps(float weight, float size);
/*
checks that feet per second is within boundaries.
if not it asks for a new chute size and adds to count.
if count is greater than 5 you fail at landing packages
*/
int main(){
	int count = 1;
	float weight = GetCargo();
	while(count <=5){
		float fps = Computefps(weight,GetChuteSize(count));
		printf("Falling at %f feet/sec.",fps);
		if (fps > max){
			printf("\nSPLAT!!!!... You need a bigger chute.\n");
			count++;
		}
		else if (fps < min){
			printf("\nTOO SLOW... Drifting too much... you need a smaller chute.\n");
			count++;
		}
		else{
			printf("\nNice landing!!!!");
			exit(0);
		}
	if(count > 5)
		printf("\nBad landing skills.... bye");
	}
	return 0;
}
//This function will return a positive number of ounces for the cargo.
float GetCargo(){
	float w;
	printf("Enter weight of cargo in ounces: ");
	scanf("%f", &w);
	while (w < 0){
		printf("ERROR!!!! BAD WEIGHT\n");
		printf("Enter weight of cargo in ounces: ");
		scanf("%f", &w);
	}
	return w;
}
/* 
	This function will return a positive number for the chute size (square feet).  
	The parameter passed to the function is the "try number".  
	It will be a value between 1 and 5).
*/
float GetChuteSize(int count){
		float s;
		printf("Try %i\n",count);
		printf("Enter chute size in square feet: ");
		scanf("%f", &s);
		while (s<1){
			printf("ERROR!!!! BAD PARACHUTE SIZE\n");
			printf("\nTry %i\n",count);
			printf("Enter chute size in square feet: \n");
			scanf("%f", &s);
		}
		return s;
}
/*
This function will compute and display the rate of descent.
The speed is returned. The formula is explained below. 
The two parameters passed to it are the weight of the cargo and the size of the chute.
*/
float Computefps(float weight, float size){
	float fps = (442.2 * sqrt(weight/16))/size;
	return fps;	
}
