# Edit by Shuanglong

mode=release

CC = g++ -std=c++17
program = TestDemo

deps = config.h

objs = Main.o                 \
	   Application.o          \
	   Utils/StringUtil.o     \
	   Utils/LogUtil.o        \
	   Utils/EnvUtil.o        \

srcs = $(objs:.o=.cpp)

$(program) : $(objs)
	$(CC) -o $(program) $(objs)

%.o : %.cpp $(deps)
ifeq ($(mode), debug)
	$(CC) -c -g $< -o $@
else
	$(CC) -c $< -o $@
endif

.PHONY:clean
clean:
	rm -rf $(objs) $(program)
