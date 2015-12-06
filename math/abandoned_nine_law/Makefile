RUNNER = bash ./runner.sh

CC=g++-4.9
#这里我在遵循freebsd的想法
CFLAGS+= -Wall -Werror
#这里直接把想要编译的文件的文件名写在
#f变量里,使用方法是make f=文件名,这样makefile里就可以使用f变量了！

run = $(RUNNER)

#注意这里由make f=获取要编译的单一文件的名字！
#其实我的很多程序都是不测试时间的，让程序通过所有测试才是我的重点工作！
all :
	$(CC) $(CFLAGS) $(file) -o a
	$(call run) 
	rm ./a
	rm -r ./output
