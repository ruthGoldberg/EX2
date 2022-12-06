#include <stdio.h>
#include "my_mat.h"


int main(){

	int i , j ;
	char input;
	

	while( (input) != 'D' ){
		
		scanf("%c" , &input);
		
		switch(input){
			
			case 'A':
				fillMyMat();
				break;
				
			case 'B':
				scanf(" %d  %d " , &i , &j );
				findPath( i , j );
				break;
			
			case 'C':
				scanf( " %d  %d " , &i , &j );
				shortPath( i , j );
				break;
				
			case 'D':
				break;
				
		}
	}

return 0;
}
			
			
			