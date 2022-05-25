CC = g++
CCFLAGS = -g

Bvector: Bvector.o Avector.o Kvector.o
	$(cc) $(CCFLAGS) -o Bvector Bvector.o Avector.o Kvector.o

BitSet: BitSet.o Bvector.o Kvector.o
	$(CC) $(CCFLAGS) -o BitSet BitSet.o Bvector.o Kvector.o

clean:
	rm -f *.o
%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<
%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<
% : %.cpp
	$(CC) $(CCFLAGS) -o $@ $<
