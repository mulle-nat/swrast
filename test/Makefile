CONFFLAGS = -D_XOPEN_SOURCE=500
OPTFLAGS = -O3 -msse2
CFLAGS = -ansi -pedantic -Wall -Wextra -I../main/include $(CONFFLAGS) $(OPTFLAGS)

.PHONY: all
all: a.out

.PHONY: clean
clean:
	$(RM) a.out *.o

a.out: window.o test.o 3ds.o ../main/libraster.a
	$(CC) $^ -lX11 -lm -o $@

../main/libraster.a:
	$(MAKE) -C ../main

# test program source
window.o: window.c window.h ../main/include/framebuffer.h
test.o: test.c window.h window.h 3ds.h ../main/include/inputassembler.h \
		../main/include/framebuffer.h ../main/include/rasterizer.h \
		../main/include/texture.h ../main/include/context.h \
		../main/include/tl.h
3ds.o: 3ds.c 3ds.h ../main/include/inputassembler.h ../main/include/context.h
