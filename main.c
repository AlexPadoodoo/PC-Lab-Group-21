#include <stdio.h>
#define MAX 100

struct cg { // structure to hold x and y coordinates and mass
    float x, y, mass;
} masses[MAX];

int readin(void)
{
    int num, i;     // num = the number of weights and i = loop counter
    
    // asks for the number of weights and read it
    printf("Enter the number of weights: ");
    scanf("%d", &num);

    // reject counts outside 1 to max 
    if (num < 1 || num > MAX) {
        printf("Error, number of weights should be between 1 and %d\n", MAX);
        return 0;  // tell main nothing has been read, so computeg is skipped
    }

    // repeat once per weight; i matches array position and starts at zero
    for (i = 0; i < num; i++) {
        printf("Enter x y mass for weight %d: ", i + 1);
        scanf("%f %f %f", &masses[i].x, &masses[i].y, &masses[i].mass);
    }

    return num; // returns the amount of weights that have been stored
}

void computecg(int n_masses)
{
    float sum_of_xmass = 0, sum_of_ymass = 0, sum_of_mass = 0;    // Running the totals 
    int i;

    for (i = 0; i < n_masses; i++) {    
        sum_of_xmass += masses[i].x * masses[i].mass;   // Multiply the weights x position by its mass and add the result to the running total
        sum_of_ymass += masses[i].y * masses[i].mass;    // Multiply the weights y position by its mass and add the result to the running total
        sum_of_mass  += masses[i].mass;     // add this weights mass to the total mass of all the weights 
    }

    if (sum_of_mass == 0) {
        printf("Error: total mass is zero.\n");   // Prevents dividing by zero if every mass is 0
        return;
    }

    printf("CoG coordinates are: x = %.2f y = %.2f\n",    // Weighted average to 2 decimal points 
           sum_of_xmass / sum_of_mass, sum_of_ymass / sum_of_mass);
}

int main(void)
{
    int number;
    if ((number = readin()) > 0)
        computecg(number);
    return 0;
}