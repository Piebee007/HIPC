#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h> 
#include <immintrin.h>
#define MAX_RAND 10000

#define BUFSIZE 10

struct sphere_t {
	double x;
	double y;
	double z;
	double r;
};

struct sphere_a{
    double *x;
    double *y;
    double *z;
    double *r;
};

double random_number() {
	// returns a random floating point number between 0.0 and MAX_RAND
	return fmod(rand() * ((double) rand() / RAND_MAX), MAX_RAND); 
}

int main(int argc, char *argv[]) {
	printf("ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh\n\n");

    // FILE *fptr1 = fopen("./timing_output.txt", "w");
    // if(fptr1 == NULL){
    //     fprintf(stderr, "Error opening file\n");
    //     exit(1);
    // }
    clock_t t; 
    t = clock(); 
    
    printf("1\n");

	// read N from the first command line argument
	int N = atoi(argv[1]);

	struct sphere_t * sphere = malloc(sizeof(struct sphere_t) * N);
	
    struct sphere_a * spheres = malloc(sizeof(struct sphere_a));
	printf("2");
	spheres->x = malloc(sizeof(double)*N);
	spheres->y = malloc(sizeof(double)*N);
	spheres->z = malloc(sizeof(double)*N);
	spheres->r = malloc(sizeof(double)*N);

	printf("3");
	// fill spheres with random numbers
	for (int i = 0; i < N; i++) {
		spheres->x[i] = random_number();
		spheres->y[i] = random_number();
		spheres->z[i] = random_number();
		spheres->r[i] = random_number()/4.0;
	}

    // fill with random numbers
	// for (int i = 0; i < N; i++) {
	// 	sphere[i].x = random_number();
	// 	sphere[i].y = random_number();
	// 	sphere[i].z = random_number();
	// 	sphere[i].r = random_number() / 4.0;
	// }
    
	// calculate areas
	// double * area = calloc(N, sizeof(double));
	// for (int i = 0; i < N; i++) {
	// 	area[i] = 4.0 * M_PI * pow(sphere[i].r, 2.0);
	// }

	double * area = calloc(N, sizeof(double));
	for (int i = 0; i < N; i++) {
		area[i] = 4.0 * M_PI * (spheres->r[i] * spheres->r[i]);
	}
    int i=0;
	double * volume = calloc(N, sizeof(double));
    
	for (i=0;i< N; i++) {
		volume[i] = (4.0 / 3.0) * M_PI* (spheres->r[i] * spheres->r[i]*spheres->r[i]);
	}
	// // calculate volume
    // int i=0;
	// double * volume = calloc(N, sizeof(double));
    // int temp = (4.0 / 3.0) * M_PI;
	// for (i=0;i< N; i++) {
	// 	volume[i] = (4.0 / 3.0) * M_PI* pow(sphere[i].r, 3.0);
    //     // volume[i+1] = (4.0 / 3.0) * M_PI * pow(sphere[i+1].r, 3.0);
    //     // volume[i+2] = (4.0 / 3.0) * M_PI * pow(sphere[i+2].r, 3.0);
    //     // volume[i+3] = (4.0 / 3.0) * M_PI * pow(sphere[i+3].r, 3.0);
	// }
    
    // for ( ; i < N; i++){
    //     volume[i] = (4.0 / 3.0) * M_PI * pow(sphere[i].r, 3.0);
        
    // }
	
	// calculate the number of spheres each sphere intersects
	// int * intersects = calloc(N, sizeof(int));
	// for (int i = 0; i < N; i++) {
	// 	for (int j = 0; j < N; j++) {
	// 		if (i == j) continue; // same circle

    //         double dx = sphere[j].x - sphere[i].x;
    //         double dy = sphere[j].y - sphere[i].y;
    //         double dz = sphere[j].z - sphere[i].z;
    //         double dist_squared = dx * dx + dy * dy + dz * dz;

    //         // Calculate the squared sum of the radii
    //         double radii_sum = sphere[j].r + sphere[i].r;
    //         double radii_sum_squared = radii_sum * radii_sum;

    //         if (dist_squared < radii_sum_squared) {
    //             intersects[i]++;
    //         }

	// 		// // calculate distance between two spheres
	// 		// double d = sqrt(pow(sphere[j].x - sphere[i].x, 2.0) + pow(sphere[j].y - sphere[i].y, 2.0) + pow(sphere[j].z - sphere[i].z, 2.0));
	// 		// // if the distance is less than the sum of the radii, they intersect
	// 		// if (d < (sphere[j].r + sphere[i].r)) intersects[i]++;
	// 	}
	// }


	int * intersects = calloc(N, sizeof(int));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue; // same circle

            double dx = spheres->x[j] - spheres->x[i];
            double dy = spheres->y[j] - spheres->y[i];
            double dz = spheres->z[j] - spheres->z[i];
            double dist_squared = dx * dx + dy * dy + dz * dz;

            // Calculate the squared sum of the radii
            double radii_sum = sphere[j].r + sphere[i].r;
            double radii_sum_squared = radii_sum * radii_sum;

            if (dist_squared < radii_sum_squared) {
                intersects[i]++;
            }

			// // calculate distance between two spheres
			// double d = sqrt(pow(sphere[j].x - sphere[i].x, 2.0) + pow(sphere[j].y - sphere[i].y, 2.0) + pow(sphere[j].z - sphere[i].z, 2.0));
			// // if the distance is less than the sum of the radii, they intersect
			// if (d < (sphere[j].r + sphere[i].r)) intersects[i]++;
		}
	}
    t = clock() - t; 
    float time_taken = ((float)t)/CLOCKS_PER_SEC;
    
    fprintf(stderr, "%f seconds taken", time_taken);

	// print out all information to the screen (consider piping this to a file)
	printf("x, y, z, r, area, volume, intersects\n");
	for (int i = 0; i < N; i++) {
		printf("%lf, %lf, %lf, %lf, %lf, %lf, %d\n", spheres->x[i], spheres->y[i], spheres->z[i], sphere[i].r, area[i], volume[i], intersects[i]);
	}

    
}
