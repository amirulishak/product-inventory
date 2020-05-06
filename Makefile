CXX=g++
CXXFLAGS=-Wall -Wextra -pedantic
EXE=app

SRCS_GLOB=src/*.cpp
SRCS=$(wildcard $(SRCS_GLOB))
OBJS=$(SRCS:.cpp=.o)

default: $(EXE)

$(EXE): $(OBJS)
	@$(CXX) $(OBJS) -o $@ 

clean:
	-rm -f $(EXE)
	-rm $(OBJS)