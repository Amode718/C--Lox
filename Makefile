CXX      := g++
CXXFLAGS := -ggdb -std=c++17
CPPFLAGS := -MMD

COMPILE  := $(CXX) $(CXXFLAGS) $(CPPFLAGS)

mylox:
	@$(COMPILE) Lox.cpp -o mylox

.PHONY: clean
clean:
	rm -f *.d *.o mylox