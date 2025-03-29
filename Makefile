CC = g++
CFLAGS = -I"./freeglut/include"
LDFLAGS = -L"./freeglut/lib" -lfreeglut -lopengl32 -lglu32
TARGET = lecture2_7

all: $(TARGET)

$(TARGET): lecture02/lecture2_7.cpp
	$(CC) lecture02/lecture2_7.cpp -o $(TARGET) $(CFLAGS) $(LDFLAGS)

clean:
	del $(TARGET).exe
