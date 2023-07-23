#include <stdio.h>
#include <math.h>

// probabilities of six possible event outcomes
float e[6] = {0.11,0.24, 0.13, 0.31, 0.19, 0.02};
int e_size = sizeof(e)/sizeof(e[0]);

// making log base equal to event outcomes count
float log_base(base, x){
    return log(x)/log(base);
}

// returns surprise - core idea of information entropy
float surprise(float probability){
    return log_base(e_size,1/probability);
}

// entropy is an expected value of event surprise outcome for the given number of times
float total_suprise(float arr_prob[], int size, int times){
    // times can be omitted and doesn't make any difference
    float total[size];
    int i = 0;
    static float sum;
    for(i = 0; i< size; i++){
        total[i] = surprise(arr_prob[i])*(arr_prob[i]*times);
        printf("%f\n",total[i]);
        sum += total[i];
    }
    return sum;
}

int main() {
    printf("Hello, World!\n");

    // times can be omitted
    int times = 10;

    float entropy = total_suprise(e, e_size, times)/times;

    printf("For %i event occurrences, Entropy value is %f\n", times, entropy);

    return 0;
}
