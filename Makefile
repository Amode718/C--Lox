CXX      := g++
CXXFLAGS := -ggdb -std=c++17
CPPFLAGS := -MMD

COMPILE  := $(CXX) $(CXXFLAGS) $(CPPFLAGS)

mylox:
	@echo "Compiling..."
	@$(COMPILE) Src/Lox.cpp -o mylox
	@echo "Compiled."

challenge081:
	@$(COMPILE) Src/Lox.cpp -o mylox

challenge08O:
	@$(COMPILE) Src/Lox.cpp -o mylox

challenge093:
	@$(COMPILE) Src/Lox.cpp -o mylox

challenge09O:
	@$(COMPILE) Src/Lox.cpp -o mylox

.PHONY: clean
clean:
	@echo "Cleaning..."
	@rm -f *.d *.o mylox
	@echo "Cleaned."