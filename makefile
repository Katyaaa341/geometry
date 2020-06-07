.PHONY: all clean
flags = gcc -Wall -Werror
bsrc = build/src
btest = build/test
main = bin/main
test = bin/test

all: $(main) $(test)

$(main): $(bsrc)/main.o $(bsrc)/name_of_figure.o $(bsrc)/crossing.o $(bsrc)/check_radius.o
	$(flags) $(bsrc)/main.o $(bsrc)/name_of_figure.o $(bsrc)/crossing.o $(bsrc)/check_radius.o -o $(main) -lm

$(bsrc)/main.o: src/main.c
	$(flags) -c src/main.c -o $(bsrc)/main.o

$(bsrc)/check_radius.o: src/check_radius.c
	$(flags) -c src/check_radius.c -o $(bsrc)/check_radius.o

$(bsrc)/crossing.o: src/crossing.c
	$(flags) -c src/crossing.c -o $(bsrc)/crossing.o -lm

$(bsrc)/name_of_figure.o: src/name_of_figure.c
	$(flags) -c src/name_of_figure.c -o $(bsrc)/name_of_figure.o

$(btest)/main.o: test/main.c
	$(flags) -I thirdparty -c test/main.c -o $(btest)/main.o

$(btest)/tests.o: test/tests.c
	$(flags) -I thirdparty -I src -c test/tests.c -o $(btest)/tests.o

$(test): $(btest)/tests.o $(btest)/main.o
	$(flags) $(bsrc)/check_radius.o $(bsrc)/crossing.o $(bsrc)/name_of_figure.o $(btest)/tests.o $(btest)/main.o -o $(test) -lm

clean:
	rm -rf $(bsrc)/*.o $(btest)/*.o bin/*
