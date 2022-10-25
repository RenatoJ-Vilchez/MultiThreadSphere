//This is a C Language program to simulate on finding the volume of a sphere through a multi thread. In addition, this is simulated in a scenario of earning points in an arcade game based on the score of a game. Furthermore, getting a PI estimate allows a view of comparing to the actual volume of a sphere, which the formula is V = 4/3 πr³//
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define AMOUNT_OF_VIDEOGAMEPOINTS 100000
#define AMOUNT_OF_THREADS 18
//This creates the amount of threads that will be set to be displayed on the console with the amount of video game points set at  100000. In addition, the number of threads that will be shown on the console is at 18. Again, consider like a simulation of finding a sphere but through the form of another scenario//

//One more note, consider the amount of threads that are set to be used in a thread like manner until it reaches the number it is set at max, in this case at 18
int Count_of_CirclePoints = 0;
pthread_mutex_t Count_of_Sphere; //Declare pthread data types to know it is a thread//
void *Find_Monte_Carlo(void * FindParameter); //Monte Carlo intergration is used for numerical intergration of pi values and it is helpful for finding the volume of a sphere//  
int main (int number_of_arg1, const char * number_of_arg2[]) {
  int POINTS_PER_THREAD = AMOUNT_OF_VIDEOGAMEPOINTS / AMOUNT_OF_THREADS; 
  double   USE_THE_PI; //A declarition of finding PI//
  pthread_t distance[AMOUNT_OF_THREADS]; 
  pthread_mutex_init(&Count_of_Sphere,NULL); int i;
  for (i = 0;i<AMOUNT_OF_THREADS;i++){ //Keep in mind that 'NULL' is a built-in constant of zero to start a pointer variable//
pthread_create(&distance[i], 0, Find_Monte_Carlo, &POINTS_PER_THREAD);
  }
  for (i = 0;i<AMOUNT_OF_THREADS;i++){
    pthread_join(distance[i], NULL);
  }
USE_THE_PI = 4.0*Count_of_CirclePoints / AMOUNT_OF_VIDEOGAMEPOINTS;  //Set at 4.0, consider that finding the volume of a spehre would be  4 * pi* r^3 /3. The 4 would represent one key of the equation that would be represented in the console ouput//
printf("----After being finished with the arcade game, this would be the estimated PI from earning %d of points which would equal to ----- = %f\n.   --In addition,this would be close to what is shown for finding a volume of a sphere---",AMOUNT_OF_VIDEOGAMEPOINTS, USE_THE_PI); 
//Print statment that gives the PI value on the estimation of a sphere//
return 0;
}
void *Find_Monte_Carlo(void * FindParameter) { 
    int pointsscored = *((int *)FindParameter); //Random points are set to be generated//
    int IngamePoints = 0;
double  z,x,y; //Decelare points of z, x, and y that will be used to help find values//
   int i;
for (i=0; i <   pointsscored;       i++){
x = ((double)rand() /   (double)   RAND_MAX)*2.0-1.0; //Random X point has been generated //
y = ((double)rand() / (double)   RAND_MAX)*2.0-1.0; //Random Y point has been generated//
x= pow(x,2.0); y = pow(y,2.0); z = sqrt(x+y); 
if (z < 1.0) { //This will help generate the random points of x and y, which would be shown in the randomizer of the scores in the aracde gamr scenario. Consider the step up of a thread and numbers//
IngamePoints++; } //By this point, x and y have been checked if there are within the sphere//
} 
printf("--- A score from a racing aracde game by a player --- = %d\n", 
//This statment will be generated score of what a player has got from a video arcade game which would be used in finding the sphere volume
IngamePoints);
pthread_mutex_lock(& Count_of_Sphere);
Count_of_CirclePoints = Count_of_CirclePoints + IngamePoints; 
pthread_mutex_unlock(& Count_of_Sphere);  
pthread_exit(0); //This would be the signal of leaving out of the emerging threads//
} 
//This is the end of the  multi thread sphere program//
