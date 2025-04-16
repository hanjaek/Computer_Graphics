CC = g++
CFLAGS = -I"./freeglut/include"
LDFLAGS = -L"./freeglut/lib" -lfreeglut -lopengl32 -lglu32
TARGET = lecture_3_4

all: $(TARGET)

$(TARGET): correct/lecture_3_4.cpp
	$(CC) correct/lecture_3_4.cpp -o $(TARGET) $(CFLAGS) $(LDFLAGS)

clean:
	del $(TARGET).exe
