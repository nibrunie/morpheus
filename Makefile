LIB_SOURCES= src/morphcode.c src/morphpoly.c
LIB_OBJECTS=$(LIB_SOURCES:.c=.o)


TEST_LIST= poly
CFLAGS += -Wall -Werror -std=c99 -g -O0

LIBOBJECT=libmorpheus.a

%.o:%.c 
	$(CC) $(CFLAGS)  -Iinclude  -c -o $@ $^

$(LIBOBJECT): $(LIB_OBJECTS)
	$(AR) rcs $@ $^

clean: 
	rm -f $(LIB_OBJECTS) $(LIBOBJECT) $(TEST_LIST)


define gen_test_rule
$(1): test/$(1).o $(LIBOBJECT)
	$(CC) $(CFLAGS) tests/$(1).o -o $(1) $(LIBOBJECT)

test: $(1)
	./$(1)
endef

$(foreach test_name,$(TEST_LIST),$(eval $(call gen_test_rule,$(test_name))))

