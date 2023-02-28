runCheck: stackDriver.o stack_II.o linked_list.o heap_usage.o
	gcc -o runCheck stackDriver.o stack_II.o linked_list.o heap_usage.o
	./runCheck
stackDriver.o: stackDriver.c stack.h
	gcc -c stackDriver.c
heap_usage.o: heap_usage.c heap_usage.h
	gcc -c heap_usage.c
linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c
stack_II.o: stack_II.c stack.h
	gcc -c stack_II.c
clean:
	rm -f *.o runCheck