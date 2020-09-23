#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<limits.h>
/*CITIES :
 KOLKATA
 BANGALORE
 MUMBAI
 CHENNAI
 HYDERABAD
 VELLORE
 NAGPUR
 PUNE
 */

/* LINKS :
 BANGALORE - PUNE - 837
 PUNE - MUMBAI - 148
 BANGALORE - VELLORE - 213
 BANGALORE - CHENNAI - 388
 VELLORE - CHENNAI - 138
 CHENNAI - HYDERABAD - 627
 VELLORE - HYDERABAD - 612
 BANGALORE. - HYDERABAD - 569
 MUMBAI - HYDERABAD - 709
 BANGALORE - KOLKATA - 1869
 BANGALORE - NAGPUR - 1092
 NAGPUR - KOLKATA - 1217
 HYDERABAD - NAGPUR - 501
 HYDERABAD - KOLKATA - 1493
 MUMBAI - NAGPUR - 803
 */
#define K 0
#define B 1
#define M 2
#define C 3
#define H 4
#define VE 5
#define N 6
#define P 7
#define V 8
#define INF 99999
void printSolution(int dist[][V],int c[][V]);

// Solves the all-pairs shortest path problem using Floyd Warshall algorithm
void floydWarshall (int graph[][V],int A[][V])
{
    /* dist[][] will be the output matrix that will finally have the shortest
     distances between every pair of vertices */
    int dist[V][V], i, j, k;
    
    /* Initialize the solution matrix same as input graph matrix. Or
     we can say the initial values of shortest distances are based
     on shortest paths considering no intermediate vertex. */
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
    
    /* Add all vertices one by one to the set of intermediate vertices.
     ---> Before start of an iteration, we have shortest distances between all
     pairs of vertices such that the shortest distances consider only the
     vertices in set {0, 1, 2, .. k-1} as intermediate vertices.
     ----> After the end of an iteration, vertex no. k is added to the set of
     intermediate vertices and the set becomes {0, 1, 2, .. k} */
    for (k = 0; k < V; k++)
    {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++)
        {
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j < V; j++)
            {
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    
    // Print the shortest distance matrix
    printSolution(dist,A);
}

/* A utility function to print solution */
void printSolution(int dist[][V] , int c[][V])
{
    printf ("The following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            c[i][j] = dist[i][j];
            //            if (dist[i][j] == INF)
            //                printf("%7s", "INF");
            //            else
            //                printf ("%7d", dist[i][j]);
        }
        //        printf("\n");
    }
}
int main()
{
    
    
    /* Weighted Undirected Graph */
    int A[8][8];
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            A[i][j] = INF;
            if(i == j)
                A[i][j] = 0;
        }
    }
    A[B][P] = 837;
    A[P][B] = 837;
    A[P][M] = 148;
    A[M][P] = 148;
    A[B][VE] = 213;
    A[VE][B] = 213;
    A[B][C] = 388;
    A[C][B] = 388;
    A[VE][C] = 138;
    A[C][VE] = 138;
    A[C][H] = 627;
    A[H][C] = 627;
    A[VE][H] = 612;
    A[H][VE] = 612;
    A[B][H] = 569;
    A[H][B] = 569;
    A[M][H] = 709;
    A[H][M] = 709;
    A[B][K] = 1869;
    A[K][B] = 1869;
    A[B][N] = 1092;
    A[N][B] = 1092;
    A[N][K] = 1217;
    A[K][N] = 1217;
    A[H][N] = 501;
    A[N][H] = 501;
    A[H][K] = 1493;
    A[K][H] = 1493;
    A[M][N] = 803;
    A[N][M] = 803;
    char s[100];
    printf("enter the cities u want to visit : ");
    scanf("%[^\n]s",s);
    char* temp;
    int list[8];
    for (int i = 0; i < 8; ++i)
    {
        list[i] = 0;
    }
    //    int count = 0;
    int visited[8];
    temp = strtok(s, " ");
    while (temp != NULL)
    {
        //        printf ("%s ",temp);
        if(strcmp(temp,"KOLKATA") == 0){
            list[K] += 1;
            visited[0] = 1;
        }
        else if(strcmp(temp,"BANGALORE") == 0){
            list[B] += 1;
            visited[1] = 1;
        }
        else if(strcmp(temp,"MUMBAI") == 0){
            list[M] += 1;
            visited[2] = 1;
        }
        else if(strcmp(temp,"CHENNAI") == 0){
            list[C] += 1;
            visited[3] = 1;
        }
        else if(strcmp(temp,"HYDERABAD") == 0){
            list[H] += 1;
            visited[4] = 1;
        }
        else if(strcmp(temp,"VELLORE") == 0){
            list[VE] += 1;
            visited[5] = 1;
        }
        else if(strcmp(temp,"NAGPUR") == 0){
            list[N] += 1;
            visited[6] = 1;
        }
        else if(strcmp(temp,"PUNE") == 0){
            list[P] += 1;
            visited[7] = 1;
        }
        else{
            printf("the city you have been trying to add to the itenay hasnt been updated in the company database Sorry!!\n");
            break;
        }
        temp = strtok (NULL, " ");
        
    }
    int final[V][V];
    floydWarshall(A,final);
    int count = 0;
    for (int i = 0; i<8; i++) {
        if(list[i] == 1)
            count += 1;
    }
    int SUB_A[count][count];
    int j = 0;
    for (int i = 0; i<8; i++) {
        if(list[i] == 1){
            int l = 0;
            for (int k = 0; k<8; k++) {
                if(list[k] == 1){
                    SUB_A[j][l] = final[i][k];
                    l++;
                }
            }
            j++;
        }
    }
    for (int i = 0; i < count; ++i)
    {
        for (int j = 0; j < count; ++j)
        {
            printf("%d ",SUB_A[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
