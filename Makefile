CC = g++
CFLAGS = -I"./freeglut/include"
LDFLAGS = -L"./freeglut/lib" -lfreeglut -lopengl32 -lglu32
TARGET = lecture3_4_2

all: $(TARGET)

$(TARGET): lecture03/lecture3_4_2.cpp
	$(CC) lecture03/lecture3_4_2.cpp -o $(TARGET) $(CFLAGS) $(LDFLAGS)

clean:
	del $(TARGET).exe
