CC=gcc
CXX=g++
BASE_DIR= .
BASE_INC= ${BASE_DIR}/include

INC= -I${BASE_INC} -Ithrift
LIBDIR= 
LIB= 
COMPILE_DIR=compile
#FLAG= ${LIBDIR} ${LIB} ${INC} -O3 -Wall -W -ansi
#FLAG= ${LIBDIR} ${LIB} ${INC} -O3 -ansi -pedantic
FLAG= ${LIBDIR} ${LIB} ${INC} -O3 -std=gnu89 -Wall -W -DNDEBUG


TARGET=GI
SRCS=$(wildcard src/*.cpp)
SRCSNOTDIR=$(notdir $(SRCS))
OBJS=$(patsubst %.cpp, compile/%.o, $(SRCSNOTDIR)) 

.PHONY: clean 

#$(shell if [ -f $(COMPILE_DIR) ]; then echo "Existed!"; else echo "NO" ;  fi;)

$(TARGET):$(OBJS)
	${CXX} -o $@ $^ ${FLAG} 

compile/%.o:src/%.cpp
	${CXX} -o $@ -c $< ${FLAG} 

clean :
	rm -rf $(TARGET) $(OBJS) 
