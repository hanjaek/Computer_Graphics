CC = g++
CFLAGS = -I"./freeglut/include"
LDFLAGS = -L"./freeglut/lib" -lfreeglut -lopengl32 -lglu32
TARGET = 3_7_0

all: $(TARGET)

$(TARGET): lecture04/final_study/3_7_0.cpp
	$(CC) lecture04/final_study/3_7_0.cpp -o $(TARGET) $(CFLAGS) $(LDFLAGS)

clean:
	del $(TARGET).exe
