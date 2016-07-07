#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define BARCODE_LENGTH 16 //default barcode length

#ifdef USE_MALLOC_WRAPPERS
#  include "malloc_wrap.h"
#endif

int main_barcode(int argc, char *argv[]){
	//assume lines are never longer than 512 char
	char line1[512],line2[512];
	char *inputfiles[2]={0,0},*outputfile=0;
	FILE *inputfp1=0,*inputfp2=0,*outputfp=stdout;
	if(argc !=3 && argc !=5){
		fprintf(stderr,"The command is bwa barcode <-o outputFile> R1file R2file\n");
		return 1;
	}
	//***********************************************************************
	//parse the command line
	//
	//check for case when there are 3 arguments (i.e. no -o flag)
	//
	//check the case when there are 5 arguments
	//check that there actually is a -o flag and an argument following it
	//********************************************************************
	
	//**********************************************************************
	//open the files
	//use fopen to open streams to the two input files and the output file if one is given
	//check that the open is successful	(i.e. that the file pointers are not 0)			
 //**********************************************************************
 
 //**********************************************************************
 //now print out a new file which is the same as file2 with the exception that
 //the header lines have a colon and the first BARCODE_LENGTH characters of the 
 //sequence line from file 1
 //
 //HINT: this can be done with one while loop using fgets, strlen and fprintf
 //HINT:  use the modulo % operator to figure out which lines are sequence lines
 //**********************************************************************

	fclose(inputfp1);
	fclose(inputfp2);
	if(outputfp !=stdout)fclose(stdout);
	return 0;
}
