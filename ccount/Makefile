# Makefile for CSV-COVARMAT tool.
# Felix Glas
# 2016-04-05 14:39:55

CXX = g++
CXXFLAGS = -pipe -O3 -Wextra -W -ansi -pedantic -pedantic-errors -Wmissing-braces -Wparentheses -std=c++14
CXXFLAGS += -Wall -Wold-style-cast -Wzero-as-null-pointer-constant
LDFLAGS = -static -static-libgcc -static-libstdc++
RM = rm -rf

all: ccount.exe

ccount.exe: ccount.o common.o
	$(CXX) $(LDFLAGS) -o $@ $^

ccount.o: ccount.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

common.o: common.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	$(RM) ccount.o
	$(RM) ccount.exe
	$(RM) common.o

delete:
	$(RM) ccount.o
	$(RM) ccount.exe
	$(RM) ccount.cc
	$(RM) common.o
	$(RM) Makefile
