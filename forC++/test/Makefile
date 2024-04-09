#使用$g++ *.cpp -o main与以下代码同样的效果 

#.PHONY:		伪指令声明,声明不生成文件的普通命令
#CC=			编译C:gcc,编译C++:g++
#SOURCES=		将所有源文件赋值给SOURCES
#OBJECTS=		将SOURCES中文件的后缀换为.o赋值给OBJECTS
#EXECUTABLE=	可执行文件名称
.PHONY:run clean makecpp makec
CC=g++
CFLAGS=
CPPFLAGS=
LDFLAGS=
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:%.cpp=%.o)
EXECUTABLE=main
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE):$(OBJECTS)#将所有目标文件生成可执行文件
	$(CC) $(OBJECTS) -o $@

.cpp.o:#将所有源文件生成目标文件,头文件的不需要写入依赖
	$(CC) -c $< -o $@

#伪指令
run:
	./main

clean:
	rm -rf *.o main

makecpp:
	$(CC) *.cpp -o $(EXECUTABLE)

makec:
	gcc *.c -o $(EXECUTABLE)