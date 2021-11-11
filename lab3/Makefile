ALL:
	g++ main.cpp Figure.h rectangle.cpp rectangle.h tvector.h tvector.cpp 
sanitize:
	g++ main.cpp Figure.h rectangle.cpp rectangle.h tvector.h tvector.cpp  -fno-omit-frame-pointer -fsanitize=address
clean:
	rm a.out *gch