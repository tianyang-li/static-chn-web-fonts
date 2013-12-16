CXX = g++
CXXFLAGS = -ggdb -O0
LDFLAGS = 
LDLIBS = 
CXX_FILES = $(wildcard *.cc)


all : static-font


static-font : 


clean :
	rm -rfv static-font *.o 


.PHONY : clean


