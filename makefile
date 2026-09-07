CXX		:= g++
CXXFLAGS:= -Wall -Wextra -std=c++11 -g

TARGET	:= taskforge

SRCS	:= main.cpp Unitgroup.cpp Item.cpp ConcreteState.cpp DepthFirstIterator.cpp \
			BreadthFirstIterator.cpp IteratorTesting.cpp Faulty.cpp Fragile.cpp \
			Hazardous.cpp UnitDecorator.cpp DecoratorTesting.cpp
OBJS	:= $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET) : $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
		$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
		./$(TARGET)

valgrind: all
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

clean:
		rm -f $(OBJS) $(TARGET)
