CXXFLAGS = -g -Wall -std=c++11
LDLIBS = -lncurses

PROJECT = eli
SRCDIR = src
OBJDIR = obj
SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o ,$(SOURCES))

.PHONY: all clean

all: $(PROJECT)

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(PROJECT): $(OBJS)
	$(CXX) $(OBJS) $(LDLIBS) -o $(PROJECT)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

clean:
	rm -f -r $(OBJDIR) $(PROJECT)
