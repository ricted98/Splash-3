TARGET = CHOLESKY

# RTEMS configuration
RTEMS_ARGV = cholesky -p@P@
RTEMS_STDIN = inputs/tk14.O
RTEMS_INIT_STACK = 64 * 1024
ROOTFS_FILES = inputs/tk14.O

OBJS = amal.o assign.o bfac.o bksolve.o block2.o fo.o malloc.o \
       mf.o numLL.o parts.o seg.o solve.o tree.o util.o

# Include the global rules
include ../../Makefile.config

amal.c: matrix.h
block2.c: matrix.h
numLL.c: matrix.h
tree.c: matrix.h
assign.c: matrix.h
fo.c: matrix.h
parts.c: matrix.h
util.c: matrix.h
bfac.c: matrix.h
malloc.c: matrix.h
seg.c: matrix.h
bksolve.c: matrix.h
mf.c: matrix.h
solve.c: matrix.h
