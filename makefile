CC=g++
CXXFLAGS=-Iinclude  -DNET_API= 
LINKFLAG= -Wl,--enable-stdcall-fixup
LIBS= -Llib -Wl,-rpath=lib -lNetSdk -lws2_32
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %cpp, %o, $(SRCS))
TARGET=veh
.PHONY : all clean
all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LINKFLAG) $(LIBS)
%o:%cpp
	$(CC) -c  $^ $(CXXFLAGS)
#veh:main.o NetCamera.o
#	g++  $(LINKFLAG) -o veh  main.o NetCamera.o $(LINKFLAG) $(LIBS)
#main.o:main.cpp
#	g++ $(CFLAGS) -c main.cpp
#NetCamera.o:NetCamera.cpp
#g++ $(CFLAGS) -c NetCamera.cpp
clean:
	rm -f $(OBJS) $(TARGET)
