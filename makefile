CXX = g++
INCLUDES = -I/usr/include/freetype2 -I/usr/include
CXXFLAGS = $(INCLUDES) -ggdb -O0 -g -Wall -W -ansi -pedantic -Wpointer-arith -Wwrite-strings -Wno-long-long -D_REENTRANT
LIBS = -lfreetype -ldl -lm -L/usr/lib -licui18n -licuuc -licudata -ldl -lm -licuio
CXX_FILES = $(wildcard *.cc)
OBJS = $(patsubst %.cc,%.o,$(CXX_FILES))


all : static-font


static-font : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(LIBS) -o static-font
	

%.o : %.cc
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<	


clean :
	rm -rfv static-font *.o 


.PHONY : clean


