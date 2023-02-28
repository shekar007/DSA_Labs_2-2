linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c
q_list.o : q_list.c q_list.h
	gcc -c q_list.c
queueDriver.o : queueDriver.c
	gcc -c queueDriver.c
runCheck : linked_list.o q_list.o queueDriver.o
	gcc -o runCheck queueDriver.o q_list.o linked_list.o
	./runCheck
clean :
	rm -f *.o runCheck