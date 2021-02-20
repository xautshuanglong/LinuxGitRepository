# Edit by Shuanglong
# https://www.cnblogs.com/Shirlies/p/4282182.html

mode=release

CC = g++ -std=c++17
CFLAGS :=
LDFLAGS :=

program = TestDemo.out

deps = config.h

#objs = Main.o                \
#	   Application.o          \
#	   Utils/StringUtil.o     \
#	   Utils/LogUtil.o        \
#	   Utils/EnvUtil.o        \

objs :=

EXT_INC :=
EXT_LIBS :=

# glibc runtime : timer_create()
EXT_LIBS += -lrt
    
SRCS += $(wildcard ./*.cpp)
UTIL_SRCS +=$(wildcard Utils/*.cpp)

objs += $(SRCS:.cpp=.o)
objs += $(UTIL_SRCS:.cpp=.o)

ifeq ($(mode), debug)
	CFLAGS +=-g
endif

$(program) : $(objs)
	$(CC) $(CFLAGS) -o $(program) $(objs) $(EXT_LIBS)

%.o : %.cpp $(deps)
	$(CC) -c $(CFLAGS) $< -o $@

#ifeq ($(mode), debug)
#	$(CC) -c -g $< -o $@
#else
#	$(CC) -c $< -o $@
#endif

.PHONY:clean
clean:
	rm -rf $(objs) $(program)
