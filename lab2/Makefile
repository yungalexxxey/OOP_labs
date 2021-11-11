ALL:
	g++ main.cpp figure.h rectangle.cpp rectangle.h tvector.cpp tvector.h 
sanitize:
	g++ main.cpp figure.h rectangle.cpp rectangle.h tvector.cpp tvector.h -fno-omit-frame-pointer -fsanitize=address
clean:
	rm a.out *gch