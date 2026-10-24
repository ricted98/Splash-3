TARGET = RADIX
OBJS = radix.o

# RTEMS configuration: the prefix tree assumes a power-of-two count
RTEMS_ARGV = radix -p@P@ -n1048576
RTEMS_POW2_ONLY = 1

# Include the global rules
include ../../Makefile.config
