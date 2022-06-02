CC = g++
sfmlpath = thirdparty/SFML
INCLUDE_SFML = -I $(sfmlpath)/include
LOCAL_INCLUDE = -I src/

all: compile link

compile:
	$(CC) $(INCLUDE_SFML) $(LOCAL_INCLUDE) -c src/main.cpp

link:
	$(CC) main.o -o basicClicker -L $(sfmlpath)/lib -l sfml-graphics -l sfml-window -l sfml-system