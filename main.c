#include <stdio.h>
#define MAX 100

struct cg{// structure to hold x and y coordinates and mass
    float x,y,mass;
}masses[MAX];

int readin( void)
{
    int num, i;
    printf("Enter the number of weights: ");
    scanf("%d", &num);

    if (num < 1 && num > MAX){     //Checks if number of weights entered is between 1 and Max
        printf("Error, number of weights should be between 1 and %d", MAX);
        return 0;
    }
    for (i = 0; i < num; i++) {
        printf("Enter the weight for x, y, and mass %d: ", i + 1);
        scanf("%f %f %f", &masses[i].x, &masses[i].y, &masses[i].mass);
    }
    return num;

}
void computecg( int n_masses)
{
    float sum_x = 0, sum_y = 0, total_mass = 0;
    int i;
    
    for (i = 0; i < n_masses; i++) {
        sum_of_xmass += masses[i].x * masses[i].mass;
        sum_of_ymass += masses[i].y * masses[i].mass;
        sum_of_mass += masses[i].mass;
    }

    if (sum_of_mass == 0) {
        printf("Error: total mass is 0 \n");
        return;
    }
    printf("CoG coordinates are: x = %.2f y = %.2f \n", sum_of_xmass / sum_of_mass, sum_of_ymass / sum_of_mass);


}
int main( void )
{
int number;
if((number = readin()) > 0)
computecg(number);
return 0;
}
