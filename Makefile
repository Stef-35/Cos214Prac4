CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2 -g
LDFLAGS = 

TARGET = taskforge

SRCS = main.cpp \
       Item.cpp \
       Unitgroup.cpp \
       UnitDecorator.cpp \
       Fragile.cpp \
       Hazardous.cpp \
       Faulty.cpp \
       DepthFirstIterator.cpp \
       BreadthFirstIterator.cpp \
       ConcreteState.cpp

HDRS = Item.h \
       Unit.h \
       Unitgroup.h \
       UnitDecorator.h \
       Fragile.h \
       Hazardous.h \
       Faulty.h \
       DepthFirstIterator.h \
       BreadthFirstIterator.h \
       UnitIterator.h \
       ProcessState.h \
       ConcreteState.h

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

debug: $(TARGET)
	gdb ./$(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)


.PHONY: all clean run debug valgrind