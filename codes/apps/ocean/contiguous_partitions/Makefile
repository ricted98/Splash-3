TARGET = OCEAN
OBJS = jacobcalc.o jacobcalc2.o laplacalc.o linkup.o main.o multi.o slave1.o slave2.o subblock.o

# RTEMS configuration
RTEMS_ARGV = ocean_contiguous_partitions -p@P@ -n258
RTEMS_POW2_ONLY = 1

# Include the global rules
include ../../../Makefile.config

decs.h: decs.h.in
jacobcalc.c: decs.h
linkup.c: decs.h
slave1.c: decs.h
jacobcalc2.c: decs.h
main.c: decs.h
slave2.c: decs.h
laplacalc.c: decs.h
multi.c: decs.h
subblock.c: decs.h
