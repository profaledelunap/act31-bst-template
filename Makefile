all: clean test1 test2 test3 test4

test1: 
ifneq ("$(wildcard ./mysolution1.txt)","")
	rm mysolution1.txt
endif
	g++ -std=c++11 test1main.cpp -o test1main
	./test1main > mysolution1.txt
	g++ -std=c++11 test1.cpp -o test1
	./test1

test2:
	g++ -std=c++11 test2.cpp -o test2
	./test2

test3:
ifneq ("$(wildcard ./mysolution3.txt)","")
	rm mysolution3.txt
endif
	g++ -std=c++11 test3main.cpp -o test3main
	./test3main > mysolution3.txt
	g++ -std=c++11 test3.cpp -o test3
	./test3

test4:
	g++ -std=c++11 test4.cpp -o test4
	./test4

clean:
ifneq ("$(wildcard ./test1)","")
	rm test1
	rm test1main
endif
ifneq ("$(wildcard ./test2)","")
	rm test2
endif
ifneq ("$(wildcard ./test3)","")
	rm test3
	rm test3main
endif
ifneq ("$(wildcard ./test4)","")
	rm test4
endif

.PHONY: main test1 test2 test3 test4