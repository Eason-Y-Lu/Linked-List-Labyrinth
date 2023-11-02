.PHONY: all

CXX = clang++
CXXFLAGS = -std=c++20 -Ofast
SOURCES = $(wildcard *.cpp)
TARGET = main

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: clean