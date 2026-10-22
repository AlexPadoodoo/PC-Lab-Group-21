#include <stdio.h>
#define MAX 100

struct cg{// structure to hold x and y coordinates and mass
    float x,y,mass;
}masses[MAX];

int readin( void)
{
    int num;
    prinf("Enter the number of weights: ");
    scanf("%d", &num);

    if (num > 1, num < MAX){     //Checks if number of weights entered is between 1 and Max

    } else{
        printf("Error");
    }

    return num;

/* Write this function to read in the data
into the array masses
note that this function should return the number of
Page 3 of 4
masses read in from the file */
}
void computecg( int n_masses)
{
    float sum_x = 0, sum_y = 0, total_mass = 0;
/* Write this function to compute the C of G
and print the result */
}
int main( void )
{
int number;
if((number = readin()) > 0)
computecg(number);
return 0;
}
