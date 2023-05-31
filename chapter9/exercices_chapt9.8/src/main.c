/*
 *
 *   Title of project :
 *   Date of creation :
 *   Author(s) : PierreLgol
 *   github : https://github.com/pierrelgol
 *
 *   More on the project :
 *
 *   #TODO(s) :
 *
 *
 */

//--------------------[     DEPENDENCIES DECLARATION     ]--------------------//

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//--------------------[     MAIN METHOD     ]--------------------------------//

int stringFind(const char *source, const char *tofind);
void stringRemove(char *source, char *rm);
void stringInsert(char *source, char *insert, size_t at);
void stringReplace(char *source, char *toreplace, char *replacement);

int main() {

	// char str1[] = "pierre ollivier";
	// char str2[] = "pierre";
	// char str3[] = "lorem pasum diffu imun";
	// char str4[] = "diffu";
	// int res1, res2;
	// res1 = stringFind(str1, str2);
	// res2 = stringFind(str3, str4);
	// printf("%s is found in %s at %d\n",str2,str1,res1);
	// printf("%s is found in %s at %d\n",str4,str3,res2);
	
	char str1[] = "pierre ollivier";
	char str2[] = "pierre";
	char str3[] = "pierro";
	char str3a[] = "rre oll";
	char str3b[] = "lliviero";

	printf("%s\n",str1);
	stringReplace(str1,str2 ,str3);
	printf("%s\n",str1);
	
	return EXIT_SUCCESS;
}

int stringFind(const char *source, const char *tofind)
{
	
	size_t slen = strlen(source), tlen = strlen(tofind), i, j;
	if(tlen > slen) return -1;
	for( i = 0, j = 0; i < slen; i++ ){
		if(source[i] == tofind[0]){
			j = i;
			while(source[j] == tofind[j-i] && (j-i) < tlen){ // j-i becomes 0 et the loop operate till it becomes == to tlen
				j++;
			}
			if ( (j - i) == tlen ){ //return the index of tofind in source, if after exiting the loop the value of j is == to tlen
				return i;
			}else {
      	j = 0;
      }
		}
	}
	return -1;
}
void stringRemove(char *source, char *rm){
	size_t slen = strlen(source), rmlen = strlen(rm), i, j;
	char *buffer = (char*) malloc(slen - rmlen);
	if(!buffer) return;
	for( i = 0, j = 0; i < slen; i++){
		if(source[i] == rm[j]){
			j++;
			continue;
		}else{
			buffer[i-j] = source[i];
		}
	}
	buffer[i-j] = '\0';
	strcpy(source,buffer);
	free(buffer);
}

void stringInsert(char *source, char *insert, size_t at){
	size_t slen = strlen(source), insertlen = strlen(insert),buffsize = slen + insertlen, i, j;
	char *buffer = (char*) malloc(buffsize);
	for ( i = 0, j = 0; i < buffsize; i++ ){
		if( i >= at){
			if( i < (at + insertlen) ){
				buffer[i] = insert[j];
				j++;
			}else{
				buffer[i] = source[i-j];
			}
		}else{
		}
	}
	buffer[i] = '\0';
	strcpy(source,buffer);
	free(buffer);
}

void stringReplace(char *source, char *toreplace, char *replacement){
	size_t at = stringFind(source,toreplace);
	stringRemove(source,toreplace);
	stringInsert(source,replacement ,at);
}
