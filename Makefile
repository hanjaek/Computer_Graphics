CC = g++
CFLAGS = -I"./freeglut/include"
LDFLAGS = -L"./freeglut/lib" -lfreeglut -lopengl32 -lglu32
TARGET = 3_7_0_a

all: $(TARGET)

$(TARGET): lecture04/final_study/3_7_0_a.cpp
	$(CC) lecture04/final_study/3_7_0_a.cpp -o $(TARGET) $(CFLAGS) $(LDFLAGS)

clean:
	del $(TARGET).exe
