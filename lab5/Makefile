ALL:
	g++ item.cpp Iter.h item.h main.cpp rectangle.cpp rectangle.h tvector.cpp tvector.h
sanitize:
	g++ item.cpp Iter.h item.h main.cpp rectangle.cpp rectangle.h tvector.cpp tvector.h -fno-omit-frame-pointer -fsanitize=address
clean:
	rm a.out *gch