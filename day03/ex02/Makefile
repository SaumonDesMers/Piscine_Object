target = soLid

CXX = clang++
CXXFLAGS = -std=c++98 -g -Wall -Wextra -Werror

VPATH =
SRCS = main.cpp
INC_DIR =

OBJ_DIR = obj
DEP_DIR = dep

#-------------------------------------------------------------

OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
DEPS = $(SRCS:%.cpp=$(DEP_DIR)/%.d)

all : $(target)

$(target) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

-include $(DEPS)

$(OBJ_DIR)/%.o : %.cpp
	@mkdir -p $(OBJ_DIR) $(DEP_DIR)
	$(CXX) $(CXXFLAGS) -o $@ -MMD -MF $(DEP_DIR)/$*.d $(INC_DIR) -c $<

clean :
	$(RM) $(OBJS) $(DEPS)

fclean : clean
	$(RM) $(target)

re : fclean
	@$(MAKE) all --no-print-directory

.PHONY : all clean fclean re