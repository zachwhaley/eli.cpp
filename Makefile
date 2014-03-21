CXX = g++
CPPFLAGS = -g -Wall -std=c++11

PROJECT = editor
SDIR = src
ODIR = obj
SOURCES = $(wildcard $(SDIR)/*.cpp)
OBJECTS = $(subst .cpp,.o,$(SOURCES))
DEPENDS = $(subst .o,.d,$(OBJECTS))

.PHONY: all clean

all: $(PROJECT)

$(PROJECT): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(PROJECT)

%.o:%.cpp
	$(CXX) $(CPPFLAGS) -MMD -c $< -o $@

clean:
	rm -f $(OBJECTS) $(DEPENDS) $(PROJECT)
