TARGET = BARNES
INPUT  = inputs/n8k-p2

# Define Objects
OBJS = posix_init.o $(basename $(INPUT)).o \
       code.o code_io.o load.o grav.o getparam.o util.o

# Include the global rules
include ../../Makefile.config

stdinc.h: code.h defs.h util.h vectmath.h load.h code_io.h grav.h getparam.h stdinc.h.in
code.o: code.c.in stdinc.h
code_io.o: code_io.c.in stdinc.h
getparam.o: getparam.c.in stdinc.h
grav.o: grav.c.in stdinc.h
load.o: load.c.in stdinc.h
util.o: util.c.in stdinc.h

# Convert Input File to Object
$(INPUT):
	@:

$(basename $(INPUT)).o: $(INPUT)
	$(OBJCOPY) -I binary -O elf64-littleriscv -B riscv $< $@
