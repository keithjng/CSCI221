CXX = g++
CCFLAGS = -g -std=c++14

all: source-stats.wc generic.wc highest

# this is a "Suffix Rule" - how to create a .o from a .cc file
.cpp.o:
	$(CXX) $(CCFLAGS) -c $<

highest: highest.o
	$(CXX) -o highest highest.o

source-stats.wc: source.txt
	wc source.txt > source.wc

# Generic rule that can turn any .txt into a .wc of the same name, simply add the file name into "all"
%.wc: %.txt
	wc $< > $(@F)

# Not a required function, but one that I found cool, it will display the word count of ALL .txt files in the directory
# total.wc: *.txt
# 	wc *.txt > total.wc

clean:
	rm -f *.o
	rm -f *.wc
