TARGET = CHOLESKY
ROOTFS_FILES = inputs/tk14.O

.PRECIOUS: $(ROOTFS_FILES)

# Define Objects
OBJS = posix_init.o rootfs.o \
       amal.o assign.o bfac.o bksolve.o block2.o fo.o malloc.o \
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

# Generate rootfs
rootfs.tar: $(ROOTFS_FILES)
	tar -cf $@ -b 1 $^

rootfs.o: rootfs.tar
	$(OBJCOPY) -I binary -O elf64-littleriscv -B riscv $< $@
