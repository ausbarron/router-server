
#include<stdio.h>

//node struct definition
struct node
{
    unsigned dist[20];
    unsigned from[20];
}rt[10];
 
int main() {
	int costMatrix[20][20]; //router cost matrix
	int numRouters,i,j,k,counter=0;
	printf("\nEnter the number of routers : ");//requests number of nodes/routers
	scanf("%d",&numRouters);//user input
	printf("\nEnter the cost matrix :\n");//requests cost matrix for routers
	for(i=0; i<numRouters; i++)//loop to number of nodes
        for(j=0; j<numRouters; j++) { //loop for matrix
		scanf("%d",&costMatrix[i][j]);
		costMatrix[i][i]=0;
		rt[i].dist[j]=costMatrix[i][j];
		rt[i].from[j]=j;
        }
        do {   //calculates tables for each router
		counter=0;
 		for(i = 0; i < numRouters; i++)
		for(j = 0; j < numRouters; j++)
		for(k = 0; k < numRouters; k++)
		if(rt[i].dist[j]>costMatrix[i][k]+rt[k].dist[j]) {
			rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
                    	rt[i].from[j]=k;
                    	counter++;
                } 
        }while(counter!=0);
        for(i = 0; i < numRouters ;i++) {//prints each table for each router
		printf("\n\nState value for router %d is \n",i+1);
		for(j = 0; j < numRouters; j++) {
			printf("\t\nnode %d via %d Distance%d",j+1,rt[i].from[j]+1,rt[i].dist[j]);
		}
        }   
    printf("\n\n");//prints two new lines for terminal clarity
}
