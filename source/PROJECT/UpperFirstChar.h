#ifndef UPPERFIRSTCHAR_H_INCLUDED
#define UPPERFIRSTCHAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///Function declaration
int IsLetter (char* c);
int LetterTarget(char* c);
char* convertStdName(char*c);

///Function definition
//IsLetter() checks if the letter is capital or small or a stray character
int IsLetter (char* c){
    /*Return value:
     *1 for Capital , 0 for Stray, and -1 for Small letter*/
	return (('A' <= *c && *c <= 'Z')) ? 1: ('a' <= *c && *c <= 'z')? -1:0;
}

/*LetterTarget() returns what the character supposes to be:*
 *1 	if the char should be capitalized*
 *-1	if the char should be small*
 *0 	if the char should be deleted*/
int LetterTarget (char * c){
	char* d  = c;
	int now = IsLetter(d),
		prev = IsLetter(--d);
		return !now ? 0: prev? -1:1;
}

//Creates new string with standard name format
char* convertStdName(char *c){
    //Dynamically creates new string
	char *NewName = (char*) malloc((size_t) 20*sizeof(char)),*ptr, *ptr2;
	strcpy(NewName,c);
	ptr = ptr2= NewName;
	int first_n = 0;

	do{
		int target = LetterTarget(ptr);
		//Terminate all strays
		while(!target && *ptr != '\0') {target = LetterTarget(++ptr);}
		//Do conversion if it's not NULL
		if (*ptr != '\0'){
			//Add one space before capital letter, but not the first one
			if (target == 1)
				if (first_n++) {*ptr2++ = ' ';}
			//Convert if the format is wrong
			if (target != IsLetter(ptr)) {(*ptr) += target*('A' -'a');}
		}
		//Update new character
	} while(*ptr2++ = *ptr++);
	//Return new string
	return NewName;
}

#endif // UPPERFIRSTCHAR_H_INCLUDED
