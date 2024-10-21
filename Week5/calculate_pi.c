#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h> 
#include <omp.h>

struct point {
    double x;
    double y;
};


// Modified from Numerical Recipes Page 340 http://numerical.recipes/book/book.html
typedef struct {
    unsigned long long u;
    unsigned long long v;
    unsigned long long w;
} random_generator;

random_generator init_random_generator(unsigned long long seed) {
    random_generator r;
    r.v = 4101842887655102017LL;
    r.w = 1;
    r.u = seed ^ r.v; 
    r.v = r.u;
    r.w = r.v;
    return r;
}

double random_double(random_generator *r) {
    //Return 64-bit random integer.
    r->u = r->u * 2862933555777941757LL + 7046029254386353087LL; 
    r->v ^= r->v >> 17; 
    r->v ^= r->v << 31; 
    r->v ^= r->v >> 8;
    r->w = 4294957665U*(r->w & 0xffffffff) + (r->w >> 32);
    unsigned long long x = r->u ^ (r->u << 21); 
    x ^= x >> 35; 
    x ^= x << 4; 
    return 5.42101086242752217E-20 * ((x + r->v) ^ r->w);
} 



double random_number() {
	// returns a random floating point number between 0.0 and 1.0
	return (rand() % 10001) / 10000.0;
}

int isPointInCircle(double x, double y){
    if ((x*x)+(y*y) <= 1.0){
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {

    random_generator my_random = init_random_generator(time(NULL));
    // double x = random_double(&my_random);
    // double y = random_double(&my_random);
    // printf("aaa %f %f", x, y);

    clock_t t; 
    t = clock(); 
    // read N from the first command line argument
	int N = atoi(argv[1]);

    struct point * points = malloc(sizeof(struct point) * N);


    // fill with random numbers
    #pragma omp parallel for
	for (int i = 0; i < N; i++) {
		points[i].x = random_double(&my_random);
		points[i].y = random_double(&my_random);
    }
    

    int points_in = 0;
    #pragma omp parallel for
    for (int i=0; i< N; i++){
        if (isPointInCircle(points[i].x, points[i].y) == 1){
            #pragma omp critical
            points_in ++;
        }
    }


    double pi = ((double)points_in/(double)N) * 4.0;

    printf("Pi is %f \n", pi);

    t = clock() - t; 
    float time_taken = ((float)t)/CLOCKS_PER_SEC;
    
    fprintf(stderr, "%f seconds taken", time_taken);

}