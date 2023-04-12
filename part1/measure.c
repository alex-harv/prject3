/**
 * Minjun Wu, 2021.02.08 Demo for cache side-channel attacks, basic
 *
 * Modified by Zhiyuan Wu for CSci 2021-010, Spring 2021
 * Modified by Jason Berry for CSci 2021-010, Spring 2023
 */
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include <sched.h>
#include "cacheutils.h"
#include <unistd.h>
#include <time.h>

const long unsigned array[2048];

#define SECRET_SIZE 8
unsigned known_secret[SECRET_SIZE] = {1, 0, 0, 1, 1, 0, 1, 0};

// measures and prints timing for determining the threshold
void probe() {
    void*  addr       = (void*) &array[512];
    size_t results[8] = {0}; // to record the latency

    for (int i = 0; i < SECRET_SIZE; i++) {
        if (known_secret[i]) {
            maccess(addr); // "victim" accesses the data
        }

        // attacker probes the access
        size_t time = rdtsc();
        maccess(addr); // attacker measures access time
        size_t delta = rdtsc() - time;
        flush(addr);

        results[i] = delta;
    }

    printf("Timing:\t");
    for (int i = 0; i < SECRET_SIZE; i++) { printf("%lu\t", results[i]); }
    putchar('\n');
}

void test(int threshold) {
    void*    addr       = (void*) &array[512];
    ssize_t results[8] = {0}; // to record the latency

    for (int i = 0; i < SECRET_SIZE; i++) {
        if (known_secret[i]) {
            maccess(addr); // "victim" accesses the data
        }

        /** TODO: MEASURE ACCESS TIMING **/
        flush(addr);

        /** TODO: UNCOMMENT THE FOLLOWING LINE AND FILL IN THE IF CONDITION **/
        // if (/* ? */) results[i] = 1;
    }
    printf("Results:\t");
    for (int i = 0; i < SECRET_SIZE; i++) { printf("%lu\t", results[i]); }
    putchar('\n');
}

int main(int argc, char* argv[]) {
    int c = -1;
    while ((c = getopt(argc, argv, "pt:")) != -1) {
        switch (c) {
            case 'p': probe(); break;
            case 't': test(atoi(optarg)); break;
            default: abort();
        }
    }
    printf("Secret:\t");
    for (int i = 0; i < SECRET_SIZE; i++) { printf("%u\t", known_secret[i]); }
    putchar('\n');
    return 0;
}
