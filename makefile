CXX = g++
CXXFLAGS = -ggdb -O0
LDFLAGS = 
LDLIBS = 


all : static-font


static-font : 


clean :
	rm -rfv static-font *.o 


.PHONY : clean


