SRC_FILES := $(wildcard *.cc)
BIN_FILES := $(patsubst %.cc,%.bin,$(SRC_FILES))


test: $(BIN_FILES)
	rm *.bin
	@echo "Done."
	

%.bin: %.cc
	-g++ $< -o $@ --std=c++11
	-./$@ > /dev/null