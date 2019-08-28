
CC = g++
CFLAGS  = -o
file := test.txt
variable := $(shell cat ${file})

$(info $(variable))
default: count
count:	lib/menu.o lib/Nonpreemptive.o lib/Preemptive.o lib/PriorityScheduling.o lib/RoundRobinscheduling.o
	$(CC) $(CFLAGS) main lib/menu.o lib/Nonpreemptive.o lib/Preemptive.o lib/PriorityScheduling.o lib/RoundRobinscheduling.o 

main.o:	lib/menu.cpp
	$(CC) -c lib/menu.cpp  

Nonpreemptive.o:	lib/Nonpreemptive.cpp
	$(CC) -c lib/Nonpreemptive.cpp 

Preemptive.o:	lib/Preemptive.cpp
	$(CC) -c lib/Preemptive.cpp 

PriorityScheduling.o:	lib/PriorityScheduling.cpp
	$(CC) -c lib/PriorityScheduling.cpp 
RoundRobinscheduling.o:	lib/RoundRobinscheduling.cpp
	$(CC) -c lib/RoundRobinscheduling.cpp 
clean:
	$(RM) count *.o *~
