PROG = ./bin/thread_pool

CXX = g++

SRC_DIRS ?= src
INCDIR = include
BUILD_DIR = obj/
BINDIR = bin

MKDIR_P	= mkdir -p

# SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
SRCS := $(wildcard $(SRC_DIRS)/*.cpp)

OBJ := $(notdir $(SRCS))
OBJ2 := $(addprefix $(BUILD_DIR), $(OBJ))
# OBJS := $(addsuffix .o,$(basename $(OBJ2)))

OBJS := $(addsuffix .o,$(basename $(SRCS)))
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(INCDIR) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP -Wall

$(PROG): $(OBJS)
	${MKDIR_P} ${BINDIR}
	$(CXX) $(LDFLAGS) $(OBJS) -o $@ $(LOADLIBES) $(LDLIBS)

.PHONY: clean
clean:
	$(RM) $(PROG) $(OBJS) $(DEPS)
	rm -fR $(BINDIR)

-include $(DEPS)
