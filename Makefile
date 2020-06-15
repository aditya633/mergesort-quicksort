
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla 
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose
#TESTFALGS = -DTEST_MAIN #s-DTEST_function

#######################################################################

SRCS = pa5.c sorting.c
OBJS = $(SRCS:%.c=%.o)

pa5: $(OBJS)
	$(GCC) $(OBJS) -o pa5
	
.c.o:
	# $(GCC) $(TESTFALGS) -c $*.c
	$(GCC) $(TESTFALGS) -c $*.c

 memory: pa5
	$(VAL) ./pa5 -q ./inputs/1M.b 1M_s.b

# testall: test1 test2 test3 test4

test1: pa5
	./pa5 -q ./inputs/10.b 10_s.b
	diff ./10_s.b ./correct_sorted.b
test2: pa5
	./pa5 -q ./inputs/30.b 30_s.b
	diff ./30_s.b ./correct_sorted.b
	
test3: pa5
	./pa5 -q ./inputs/1M.b 1M_s.b
	diff ./1M_s.b ./correct_sorted.b
test4: pa5
	./pa5 -m ./inputs/10.b 10_s_merge.b

test5: pa5
	./pa5 ./example/1K.po outputs/1K.pr ./outputs/1K.dim ./outputs/1K.pck

clean: # remove all machine generated files
	rm -f pa5 *.o
	rm -f *.b 
