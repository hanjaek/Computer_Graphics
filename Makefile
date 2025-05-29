CC = g++
CFLAGS = -I"./freeglut/include"
LDFLAGS = -L"./freeglut/lib" -lfreeglut -lopengl32 -lglu32
TARGET = lecture4_11

all: $(TARGET)

$(TARGET): lecture04/lecture4_11.cpp
	$(CC) lecture04/lecture4_11.cpp -o $(TARGET) $(CFLAGS) $(LDFLAGS)

clean:
	del $(TARGET).exe
