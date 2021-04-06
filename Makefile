# Set the following to '0' to disable log messages:
LOGGER ?= 1

# Compiler/linker flags
CFLAGS += -g -Wall -fPIC -DLOGGER=$(LOGGER)
LDLIBS += -lm
LDFLAGS +=

# output binary name
bin=ds

src=linked_list.c clist.c ds.c
obj=$(src:.c=.o)

all: $(bin) libclist.so

$(bin): $(obj)
	$(CC) $(CDFLAGS) $(LDLIBS) $(LDFLAGS) $(obj) -o $@

libclist.so: clist.o
	$(CC) $(CFLAGS) $(LDLIBS) $(LDFLAGS) $^ -shared -o $@

clist.o: clist.c clist.h

linked_list: linked_list.c
	gcc -g -Wall linked_list.c -o linked_list

ds.o: ds.c clist.h linked_list.h

clean:
	rm -f *.o
	rm -f linked_list
	rm -f libclist.so
	rm -f $(bin)
	rm -f $(obj)

test: $(bin) libds.so ./tests/run_tests
	@DEBUG="$(debug)" ./tests/run_tests $(run)

