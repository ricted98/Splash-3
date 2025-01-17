.PHONY: all clean

NUM_HARTS ?= 1

# create a minimal directory to be included in the fpga image
splash3 :
	mkdir -p                                       $@/codes/apps/barnes/inputs
	cp apps/barnes/BARNES                          $@/codes/apps/barnes/
	cp apps/barnes/inputs/n8k-p$(NUM_HARTS)                   $@/codes/apps/barnes/inputs/

	mkdir -p                                       $@/codes/apps/fmm/inputs
	cp apps/fmm/FMM                                $@/codes/apps/fmm/
	cp apps/fmm/inputs/input.$(NUM_HARTS).16384               $@/codes/apps/fmm/inputs/

	mkdir -p                                       $@/codes/apps/ocean/contiguous_partitions
	cp apps/ocean/contiguous_partitions/OCEAN      $@/codes/apps/ocean/contiguous_partitions/

	mkdir -p                                       $@/codes/apps/radiosity
	cp apps/radiosity/RADIOSITY                    $@/codes/apps/radiosity/

	mkdir -p                                       $@/codes/apps/water-nsquared/inputs
	cp apps/water-nsquared/WATER-NSQUARED          $@/codes/apps/water-nsquared/
	cp apps/water-nsquared/random.in               $@/codes/apps/water-nsquared/
	cp apps/water-nsquared/inputs/n512-p$(NUM_HARTS)          $@/codes/apps/water-nsquared/inputs/

	mkdir -p                                       $@/codes/apps/water-spatial/inputs
	cp apps/water-spatial/WATER-SPATIAL            $@/codes/apps/water-spatial/
	cp apps/water-spatial/random.in                $@/codes/apps/water-spatial/
	cp apps/water-spatial/inputs/n512-p$(NUM_HARTS)           $@/codes/apps/water-spatial/inputs/

	mkdir -p                                       $@/codes/kernels/cholesky/inputs
	cp kernels/cholesky/CHOLESKY                   $@/codes/kernels/cholesky/
	cp kernels/cholesky/inputs/tk14.O              $@/codes/kernels/cholesky/inputs/

	mkdir -p                                       $@/codes/kernels/fft
	cp kernels/fft/FFT                             $@/codes/kernels/fft/

	mkdir -p                                       $@/codes/kernels/lu/contiguous_blocks
	cp kernels/lu/contiguous_blocks/LU             $@/codes/kernels/lu/contiguous_blocks/

	mkdir -p                                       $@/codes/kernels/lu/non_contiguous_blocks
	cp kernels/lu/non_contiguous_blocks/LU         $@/codes/kernels/lu/non_contiguous_blocks/

	mkdir -p                                       $@/codes/kernels/radix
	cp kernels/radix/RADIX                         $@/codes/kernels/radix/


splash3/runtest : splash3
	echo "cd /perf/splash3/codes/apps/barnes" > $@
	echo "echo BARNES" >> $@
	echo "./BARNES < inputs/n8k-p$(NUM_HARTS)" >> $@

	echo "cd /perf/splash3/codes/apps/fmm" >> $@
	echo "echo FMM" >> $@
	echo "./FMM < inputs/input.$(NUM_HARTS).16384" >> $@

	echo "cd /perf/splash3/codes/apps/ocean/contiguous_partitions" >> $@
	echo "echo OCEAN CONTIGUOUS" >> $@
	echo "./OCEAN -p$(NUM_HARTS) -n258" >> $@

	echo "cd /perf/splash3/codes/apps/radiosity" >> $@
	echo "echo RADIOSITY" >> $@
	echo "./RADIOSITY -p $(NUM_HARTS) -ae 5000 -bf 0.1 -en 0.05 -room -batch" >> $@

	echo "cd /perf/splash3/codes/apps/water-nsquared" >> $@
	echo "echo WATER NSQUARED" >> $@
	echo "./WATER-NSQUARED < inputs/n512-p$(NUM_HARTS)" >> $@

	echo "cd /perf/splash3/codes/apps/water-spatial" >> $@
	echo "echo WATER SPATIAL" >> $@
	echo "./WATER-SPATIAL < inputs/n512-p$(NUM_HARTS)" >> $@

	echo "cd /perf/splash3/codes/kernels/cholesky" >> $@
	echo "echo CHOLESKY" >> $@
	echo "./CHOLESKY -p$(NUM_HARTS) < inputs/tk14.O" >> $@

	echo "cd /perf/splash3/codes/kernels/fft" >> $@
	echo "echo FFT" >> $@
	echo "./FFT -p$(NUM_HARTS) -m16" >> $@

	echo "cd /perf/splash3/codes/kernels/lu/contiguous_blocks" >> $@
	echo "echo LU CONTIGUOUS" >> $@
	echo "./LU -p$(NUM_HARTS) -n512" >> $@

	echo "cd /perf/splash3/codes/kernels/lu/non_contiguous_blocks" >> $@
	echo "echo LU NON CONTIGUOUS" >> $@
	echo "./LU -p$(NUM_HARTS) -n512" >> $@

	echo "cd /perf/splash3/codes/kernels/radix" >> $@
	echo "echo RADIX" >> $@
	echo "./RADIX -p$(NUM_HARTS) -n1048576" >> $@

	chmod +x $@

all:
	$(MAKE) -C apps/barnes
	$(MAKE) -C apps/fmm
	$(MAKE) -C apps/ocean/contiguous_partitions
	$(MAKE) -C apps/radiosity
	$(MAKE) -C apps/water-nsquared
	$(MAKE) -C apps/water-spatial
	$(MAKE) -C kernels/cholesky
	$(MAKE) -C kernels/fft
	$(MAKE) -C kernels/lu/contiguous_blocks
	$(MAKE) -C kernels/lu/non_contiguous_blocks
	$(MAKE) -C kernels/radix
	$(MAKE)  splash3/runtest

clean:
	rm -rf splash3
	$(MAKE) -C apps/barnes clean
	$(MAKE) -C apps/fmm clean
	$(MAKE) -C apps/ocean/contiguous_partitions clean
	$(MAKE) -C apps/radiosity clean
	$(MAKE) -C apps/water-nsquared clean
	$(MAKE) -C apps/water-spatial clean
	$(MAKE) -C kernels/cholesky clean
	$(MAKE) -C kernels/fft clean
	$(MAKE) -C kernels/lu/contiguous_blocks clean
	$(MAKE) -C kernels/lu/non_contiguous_blocks clean
	$(MAKE) -C kernels/radix clean
