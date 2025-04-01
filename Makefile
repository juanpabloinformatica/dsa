CXXFLAGS := -g -Wall -Werror
CXX  := gcc
TARGET_EXEC  := dsa

BUILD_DIR:= ./build
INC_DIR:= ./include

SRCS:= $(shell find -type f -name "*.c")
OBJS:= $(SRCS:%=$(BUILD_DIR)/%.o)

INC_DIRS:= $(INC_DIR)/src
INC_DIRS+= $(INC_DIR)/test
INC_FLAGS := $(addprefix -I,$(INC_DIRS))
CPPFLAGS := $(INC_FLAGS) -MMD -MP


$(BUILD_DIR)/$(TARGET_EXEC):$(OBJS)
	$(CXX)  $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.c.o:%.c
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@


.PHONY: clean
clean:
	rm -r $(BUILD_DIR)
