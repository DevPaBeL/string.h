.PHONY: all s21_string.a test gcov_report clean rebuild

CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -g
GCOVFLAGS=-fprofile-arcs -ftest-coverage

OS = $(shell uname)
ifeq ($(OS), Linux)
	CHECKFLAGS=-lcheck -lsubunit -lm
	LDFLAGS=-lgcov
else ifeq ($(OS), Darwin)
	CHECKFLAGS=-lcheck
	LDFLAGS=
endif

all: test

s21_string.a: *.c s21_string.h
	$(CC) $(CFLAGS) -c *.c
	ar rcs s21_string.a *.o
	ranlib s21_string.a
	rm -rf *.o

test: s21_string.a
	$(CC) $(CFLAGS) -c tests/*.c
	$(CC) $(CFLAGS) *.o s21_string.a -o test $(CHECKFLAGS)
	rm -f *.o tests/*.o
	./test

gcov_report: test
	$(CC) $(CFLAGS) *.c tests/*.c $(GCOVFLAGS) -o report.out $(CHECKFLAGS) $(LDFLAGS)
	./report.out
	find ./ -type f -iname '*.gcda'
	lcov -o report.info -c -d .
	rm -rf ./cov-report
	mkdir ./cov-report
	genhtml -o ./cov-report/ report.info
	open ./cov-report/index.html
	rm -rf *.gcno *.gcda report.out report.info ./report.out.dSYM/

clean:
	rm -rf ./s21_string.a ./test ./*.o ./cov-report/

rebuild: clean all

