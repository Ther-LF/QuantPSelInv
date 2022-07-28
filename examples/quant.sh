#!/bin/bash
mpirun -n 4  ./run_pselinv_linux_release_v2.0 -H H180.csc -r 2 -c 2
mpirun -n 4  ./run_pselinv_linux_release_v2.0 -H H180.csc -r 2 -c 2 -Q 26,0 26,1 26,2 26,3 
# for((i=0; i<=26; i++))
# do
# mpirun -n 4 ./run_pselinv_linux_release_v2.0 -H H180.csc -Q 26,$i
# mpirun -n 4 ./run_pselinv_linux_release_v2.0 -H H180.csc -Q $i,0
# done
