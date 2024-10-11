#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>

#define FILLBYTE 0b11111011

// time in microseconds
long time_diff(struct timeval start, struct timeval end) {
    return (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <memory_size_in_MB> <Read_size_in_KB> <Wait_time_in_seconds>\n", argv[0]);
        return 1;
    }

    // arg parse
    size_t memory_size = atoi(argv[1]) * 1024 * 1024; 
    int rsize = (1024 * atoi(argv[2]));
    int wait_time = atoi(argv[3]);

    // malloc alloc
    struct timeval start, end;
    gettimeofday(&start, NULL);
    char *memory_block = (char *)malloc(memory_size);
    if (memory_block == NULL) {
        perror("malloc failed");
        return 1;
    }

    // fill with 1s 
    memset(memory_block, FILLBYTE, memory_size);
    gettimeofday(&end, NULL);
    printf("Memory allocated and filled in %ld microseconds\n", time_diff(start, end));


    while (1) {
        sleep(wait_time);

        // readback time
        gettimeofday(&start, NULL);
        volatile char temp;
        for (size_t i = 0; i < memory_size; i += rsize) {
            temp = memory_block[i];  // copy to buffer space
        }
        gettimeofday(&end, NULL);
        printf("Memory read back in %ld microseconds\n", time_diff(start, end));
    }


    free(memory_block); // free on control+c exit

    return 0;
}

