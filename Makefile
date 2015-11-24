CXXFLAGS = -g -Wall -std=c++11
LDLIBS = -lncurses

PROJECT = eli
SRCDIR = src
OBJDIR = obj
SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
DEPS := $(OBJS:.o=.d)

.PHONY: all clean

all: $(PROJECT)

sinclude $(DEPS)

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(PROJECT): $(OBJS)
	$(CXX) $(OBJS) $(LDLIBS) -o $(PROJECT)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -f -r $(OBJDIR) $(PROJECT)
