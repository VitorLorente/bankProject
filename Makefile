CXX ?= g++
CXXFLAGS ?= -std=c++11 -Wall -Wextra -Wpedantic
CPPFLAGS ?= -Iinclude
LDFLAGS ?=
LDLIBS ?=

.DEFAULT_GOAL := usage

TARGET := build/bankProject
SOURCES := main.cpp $(wildcard src/*.cpp)
OBJECTS := $(patsubst %.cpp,build/%.o,$(SOURCES))
DEPENDS := $(OBJECTS:.o=.d)

.PHONY: compile clean usage

usage:
	@echo "Use 'make compile' para compilar o projeto."

compile: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

build/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -MMD -MP -c $< -o $@

-include $(DEPENDS)

clean:
	rm -rf build
