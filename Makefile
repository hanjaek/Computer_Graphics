CC = g++
CFLAGS = -I"./freeglut/include"
LDFLAGS = -L"./freeglut/lib" -lfreeglut -lopengl32 -lglu32
TARGET = study3-3

all: $(TARGET)

$(TARGET): study/study3-3.cpp
	$(CC) study/study3-3.cpp -o $(TARGET) $(CFLAGS) $(LDFLAGS)

clean:
	del $(TARGET).exe
