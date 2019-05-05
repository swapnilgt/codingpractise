CXX=g++
RM=rm -f
CFLAGS  = -g -Wall
CPPFLAGS=-g $(shell root-config --cflags)
INCLUDES = -I./mylib/include
SRCS = mylib/binarytree.cpp mylib/xorll.cpp mylib/utils.cpp mylib/trie.cpp mylib/linkedlist.cpp dailycodingproblem/problem22/solution1.cpp
MAIN = a.out

# define the CPP object files
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
OBJS = $(SRCS:.cpp=.o)

all: $(MAIN)

$(MAIN): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o a.out

%.o: %.cpp
	$(CXX) -c $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	rm *.o
