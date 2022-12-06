#include "my_mat.h"
#include <stdio.h>
#define matSize 10 
#define INF 999999


//global variable
int mat[matSize][matSize]={0};


// this function fills all the places that contains '0' with INF 
 
void fillInf(){ 
	for(int i = 0 ; i < matSize ; i++){
		for(int j = 0 ; j < matSize ; j++){
			if(( mat[i][j] == 0 ) && ( i !=j ) ){
				mat[i][j] = INF;
			}
		}
	}
}

// this function gets all the mats' values

void fillMyMat (){
	for (int i=0 ; i < matSize ; i++){
		for(int j=0 ; j < matSize ; j++){
				int temp;
				scanf("%d " , &temp);
				mat[i][j]=temp;
		}
	}
	fillInf();
}

void floydWarshall() {

    for (int k = 0; k < matSize; k++) {
        // Pick all vertices as source one by one
        for (int i = 0; i < matSize; i++) {
            // Pick all vertices as destination for the
            // above picked source
            for (int j = 0; j < matSize; j++) {
                // If vertex k is on the shortest path from
                // i to j, then update the value of
                // dist[i][j]
                if (mat[i][k] + mat[k][j] < mat[i][j])
                    mat[i][j] = mat[i][k] + mat[k][j];
            }
        }
    }
 
}



// this function returns 'True' if there is a path between two vertices even if not direct

void findPath (int i , int j){
	floydWarshall();
	if ( ( i == j ) || (mat[i][j] == INF) )
		printf("False\n");	
else
		printf("True\n");
}

//this function returns the shorter path between two vertices, '-1' if ther is no path

void shortPath(int i , int j){
	floydWarshall();
	if( ( !mat[i][j] ) || (mat[i][j] == INF)  )
		printf("-1\n");
	else{
		printf("%d\n" , mat[i][j]);
	}
}


