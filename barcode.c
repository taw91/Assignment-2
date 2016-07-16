#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define BARCODE_LENGTH 16 //default barcode length

#ifdef USE_MALLOC_WRAPPERS
#  include "malloc_wrap.h"
#endif

int main_barcode(int argc, char *argv[]){
	//assume lines are never longer than 512 char
	int i = 0;
	char line1[512],line2[512];
	char *inputfiles[2]={0,0},*outputfile=0;
	FILE *inputfp1=0,*inputfp2=0,*outputfp=stdout;
	if(argc !=3 && argc !=5){
		fprintf(stderr,"The command is bwa barcode <-o outputFile> R1file R2file\n");
		return 1;
	}
	if(argc == 3 ){
		inputfiles[0] = argv[0];
		inputfiles[1] = argv[1];
		outputfile = argv[2];
	}

	if(argc == 5 ) {
		outputfile = argv[2];
		inputfiles[0] = argv[3];
		inputfiles[1] = argv[4];
	}
	//***********************************************************************
	//parse the command line
	//
	//check for case when there are 3 arguments (i.e. no -o flag)
	//
	//check the case when there are 5 arguments
	//check that there actually is a -o flag and an argument following it
	//********************************************************************
	inputfp1 = fopen(inputfiles[0],"r");
	inputfp2 = fopen(inputfiles[1],"r");
	outputfp = fopen(outputfile,"w");
	if (inputfp1 == 0){
		fprintf(stdout, "input file 1 did not open");
		getchar();
		return 0;
	}
	if (inputfp2 == 0){
		fprintf(stdout, "input file 2 did not open");
		getchar();
		return 0;
	}
	if(outputfp == 0){
		fprintf(stdout, "output file did not open");
		getchar();
		return 0;
	}
	//**********************************************************************
	//open the files
	//use fopen to open streams to the two input files and the output file if one is given
	//check that the open is successful	(i.e. that the file pointers are not 0)
 //**********************************************************************
	while(fgets(line1, 512, inputfp1)){
		char tempString[512];
		char tempString2[512];
		i++;
		fgets(line2, 512, inputfp2);
		if(i % 4 == 1){
			memset(tempString, '\0', sizeof(tempString));
			strncpy(tempString, line2, strlen(line2)-1);
			fprintf(outputfp, "%s:", tempString);
		}
		if(i % 4 == 2){
			memset(tempString2, '\0', sizeof(tempString2));
			strncpy(tempString2, line1, BARCODE_LENGTH);
			fprintf(outputfp, "%s\n", tempString2);
			fprintf(outputfp, "%s", line2);
		}
		if(i % 4 == 3){
			strcpy(tempString, line2);
			fprintf(outputfp, "%s", tempString);
		}
		if(i % 4 == 0){
			strcpy(tempString, line2);
			fprintf(outputfp, "%s", tempString);
		}
	}
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
	if(outputfp != stdout)fclose(outputfp);
	return 0;
}
