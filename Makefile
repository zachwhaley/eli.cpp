CXX = g++
CPPFLAGS = -g -Wall -std=c++11
LIBS = -lncurses

PROJECT = eli
SRCDIR = src
OBJDIR = obj
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o ,$(SOURCES))

.PHONY: all clean

all: $(PROJECT)

$(OBJECTS): | $(OBJDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(PROJECT): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LIBS) -o $(PROJECT)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CPPFLAGS) -MMD -c $< -o $@

clean:
	rm -f -r $(OBJDIR) $(PROJECT)
