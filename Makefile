CC = g++
CFLAGS = -I"./freeglut/include"
LDFLAGS = -L"./freeglut/lib" -lfreeglut -lopengl32 -lglu32
TARGET = lecture2_3

all: $(TARGET)

$(TARGET): lecture2_3.cpp
	$(CC) lecture2_3.cpp -o $(TARGET) $(CFLAGS) $(LDFLAGS)

clean:
	del $(TARGET).exe
