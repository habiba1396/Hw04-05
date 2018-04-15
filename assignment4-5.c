/***************************************************************************/
/* Genevieve Grivas ********************************************************/
/* Adehla Habib ************************************************************/
/* Brandon Thorne **********************************************************/
/***************************************************************************/
/* Assignment04_05 *********************************************************/
/***************************************************************************/

/***************************************************************************/
/* Includes ****************************************************************/
/***************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<math.h>

#include<clcg4.h>

#include<mpi.h>
#include<pthread.h>

/***************************************************************************/
/* Defines *****************************************************************/
/***************************************************************************/

#define ALIVE 1
#define DEAD  0

#define u_size 1024 //world size 1024x1024
#define num_ticks 128 //128 ticks

/***************************************************************************/
/* Global Vars *************************************************************/
/***************************************************************************/

int mpi_myrank; //rank id
int mpi_commsize; //number of total ranks
//MPI Send and Recv - not sure if we need
MPI_Status status; 
MPI_Request send_request, recv_request;
int ierr;
int *sendbuff, *recvbuff;
//input arguments
int num_pthreads; //number of pthreads
double threshold; //threshold value
//Run Time
double start_time, end_time; //beginning and end time of program
//Program Variables
int rows_per_rank; //number of rows per rank
int **my_rows; //allocated number of rows per rank

/***************************************************************************/
/* Function Decs ***********************************************************/
/***************************************************************************/

// You define these

//Funtion ran in each pthread
void *run_simulation(void *)
{

    /*for (ticks t = 0 ; t < number_of_ticks ; t++)
    {
        (i.) Exchange row data with different MPI ranks for the ghost rows (the rows shared between MPI ranks). You exchange this (ghost) row data from thread 0 of each MPI rank. Be careful here on how to use mutexes so as to avoid deadlocks. Also note that this row exchange uses alive/dead status data from the previous tick.
        (ii.) Read all the statuses of the neighbors depending upon the number of live/dead neighbors for the current tick and set the appropiate live/dead count.
        (iii.) Finally, update the cell status depending on the status of your neighbors based on the rules of Game-Of-Life for that current tick.
    }*/
    
}


/***************************************************************************/
/* Function: Main **********************************************************/
/***************************************************************************/

int main(int argc, char *argv[])
{
//    int i = 0;
    int mpi_myrank;
    int mpi_commsize;
// Example MPI startup and using CLCG4 RNG
    MPI_Init( &argc, &argv);
    MPI_Comm_size( MPI_COMM_WORLD, &mpi_commsize);
    MPI_Comm_rank( MPI_COMM_WORLD, &mpi_myrank);
    
// Init 16,384 RNG streams - each rank has an independent stream
    InitDefault();
    
// Note, used the mpi_myrank to select which RNG stream to use.
// You must replace mpi_myrank with the right row being used.
// This just show you how to call the RNG.    
    printf("Rank %d of %d has been started and a first Random Value of %lf\n", 
	   mpi_myrank, mpi_commsize, GenVal(mpi_myrank));
    
    MPI_Barrier( MPI_COMM_WORLD );
    
// Insert your code

//Get number of pthreads and threshold value
    num_pthread = argv[1]; //number of pthreads
    threshold = argv[2];
	
//Start time of program
    if (mpi_myrank == 0)
    {
    	start_time = MPI_Wtime();
    }	
	
//determine number of rows for each rank
    rows_per_rank = u_size/mpi_commsize; //number of rows per rank
	
//allocate space for rows and columns on each rank
    my_rows = (int **)calloc(rows_per_rank, sizeof(int*));
	
   for (int i=0; i<rows_per_rank; i++)
   {
	my_rows[i] = (int *)calloc(usize, sizeof(int));
   }
	
//Randomly initialize universe
    for (int i=0; i<rows_per_rank; i++)
    {
    	for (int j=0; j < usize; j++)
    	{
    		if (GenVal(mpi_myrank*rows_per_rank+i) > threshold)
    		{
    			my_row[i][j] = ALIVE;
    		}
    		else
    		{
    			my_row[i][j] = DEAD;
    		}
    	}
    }
	
//Create Pthreads
    pthread_t 
    for(int i=0; i < num_pthreads; i++){

        //create pthreads

    }

//play the game
    for(int i = 0; i < num_ticks; i++)
    {
	
    }

    MPI_Barrier();	
	
//End time of program
    if (mpi_myrank == 0)
    {
     	end_time = MPI_Wtime();
    }

//Free allocated memory
    for(int i=0; i < rows_per_rank, i++){
        free(my_rows[i]);
    }
    free(my_rows);
	
// END -Perform a barrier and then leave MPI
    MPI_Barrier( MPI_COMM_WORLD );
    MPI_Finalize();
    return 0;
}

/***************************************************************************/
/* Other Functions - You write as part of the assignment********************/
/***************************************************************************/
