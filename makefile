# Compiler options
CC=g++.exe

CPPFLAGS= -c -Wall  

GFLAGS = -g 

INC_DIR = include  
INC_DIR_TEST = test

TST += \
	container-test.cpp
VPATH += test/ 

TESTLIB += \
	test/lib/gtest_main.a\
	test/lib/libgtest.a

SRC	+= \
	iterator-traits.cpp\
	myvector.cpp\
	main.cpp\
	mylist.cpp

BIN = bin

TSTBIN = test/bin


#.PHONY: all

all: program.exe test.exe

# Where $@ is a macros to define name of the file to be made
# Where $? is a macros to insert names of dependencies not to rewrite

OBJ	= $(patsubst %.cpp, $(BIN)/%.o, $(SRC))

TSTOBJ = $(patsubst %.cpp, $(TSTBIN)/%.o, $(TST))

program.exe: $(OBJ)  
	$(CC) $(GFLAGS) $? -o $@ 
	
test.exe: $(TSTOBJ) $(TESTLIB) $(BIN)/myvector.o
	$(CC) $(GFLAGS) $(TESTLIB) $(BIN)/myvector.o $< -o $@

$(BIN)/%.o: src/%.cpp 
	$(CC) $(CPPFLAGS) -I$(INC_DIR) $< -o $@ 

$(TSTBIN)/%.o: test/%.cpp
	$(CC) $(CPPFLAGS) -I$(INC_DIR_TEST) -I$(INC_DIR) $< -o $@ 

#.PHONY:
clean:
	rm *.o *.exe bin/*.o test/bin/*.o 





