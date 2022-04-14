SOURCES  =  main.cpp duration.cpp
OBJECTS  =  $(SOURCES:.cpp=.o)
TARGET   =  time
#LIBS     =  $(shell sdl-config --libs) -lGL -lGLU -lglut -lm

all: $(OBJECTS)
	g++ -o $(TARGET) $(OBJECTS) #LIBS


%o: %cpp
	g++ -o $@ -c $<


x: all
	./$(TARGET)


clean: 
	rm -rf $(OBJECTS)
	rm -rf *.o


superclean: clean
	rm -rf $(TARGET)

