# Each benchmark is built once and runs on 1..SPLASH_MAX_PROCS cores: the
# processor count is taken from the processors online at boot.

DIRS := apps/barnes \
        apps/fmm \
        apps/ocean/contiguous_partitions \
        apps/radiosity \
        apps/water-nsquared \
        apps/water-spatial \
        kernels/cholesky \
        kernels/fft \
        kernels/lu/contiguous_blocks \
        kernels/lu/non_contiguous_blocks \
        kernels/radix
# Not ported yet: apps/ocean/non_contiguous_partitions apps/raytrace apps/volrend

BINDIR ?= $(CURDIR)/bin

.PHONY: all install clean $(DIRS)

all: $(DIRS)

$(DIRS):
	$(MAKE) -C $@

# Copy all executables into $(BINDIR)
install: all
	for d in $(DIRS); do $(MAKE) -C $$d install BINDIR=$(BINDIR) || exit 1; done

clean:
	for d in $(DIRS); do $(MAKE) -C $$d clean || exit 1; done
	rm -rf $(CURDIR)/bin
