stats : prelab13.o libbasicplayer.a
	compile prelab13.o -lbasicplayer -L. -o stats

prelab13.o : prelab13.c basicplayer.h
	compile -c prelab13.c

clean:
	@rm -f *.o
	@rm -f stats
	@echo "All clean!"
