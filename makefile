CXX = g++
INCLUDES = -I/usr/include/freetype2
CXXFLAGS = $(INCLUDES) -ggdb -O0
LIBS = -lfreetype
CXX_FILES = $(wildcard *.cc)
OBJS = $(patsubst %.cc,%.o,$(CXX_FILES))


all : static-font


static-font : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(LIBS) -o static-font
	

obj/%.o : src/%.cc
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<	


clean :
	rm -rfv static-font *.o 


.PHONY : clean


