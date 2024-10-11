# C_memory_readback_bench
 simple write & readback test in C

```
% gcc -o memory_test memory_test.c

% ./memory_test                   
Usage: ./memory_test <memory_size_in_MB> <Read_size_in_KB> <Wait_time_in_seconds>

% ./memory_test 512 1 5 
Memory allocated and filled in 98484 microseconds
Memory read back in 61876 microseconds
Memory read back in 10966 microseconds
Memory read back in 20339 microseconds


% ./memory_test 512 64 5
Memory allocated and filled in 67736 microseconds
Memory read back in 6501 microseconds
Memory read back in 748 microseconds
Memory read back in 2047 microseconds
```
