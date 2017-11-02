all: hello-cpp-world hello-c-world
#all: hello-cpp-world

%: %.cc
	g++ -std=c++11 $< -o $@ -lpthread

%: %.c
	gcc $< -o $@

