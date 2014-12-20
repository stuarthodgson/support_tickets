.PHONY: all libs sim clean
all: sim

build :
	mkdir build

build/runsim.do: printf_vpi.c |build
	echo "alib work" > $@
	echo "set worklib work" >> $@
	echo "ccomp -verbose -dbg -pli -o libvpi_test.dll ../printf_vpi.c" >> $@
	echo "alog -dbg ../sample_module.v" >> $@
	echo "asim $(ASIM_ARGS) +access +w +O2 -dbg -pli libvpi_test  sample_module" >> $@
	echo "run 20ms" >> $@
	echo "endsim" >> $@


sim: build/runsim.do
	cd build && vsimsa -do runsim.do | tee sim.log

clean::
	rm -rf build

