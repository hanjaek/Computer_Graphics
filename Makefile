CC = g++
CFLAGS = -I"./freeglut/include"
LDFLAGS = -L"./freeglut/lib" -lfreeglut -lopengl32 -lglu32
TARGET = lecture_3_5_2_strip

all: $(TARGET)

$(TARGET): correct/lecture_3_5_2_strip.cpp
	$(CC) correct/lecture_3_5_2_strip.cpp -o $(TARGET) $(CFLAGS) $(LDFLAGS)

clean:
	del $(TARGET).exe
