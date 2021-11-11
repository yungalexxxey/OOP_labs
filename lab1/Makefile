ALL:
	g++ main.cpp figure.h rectangle.cpp rectangle.h rhombus.cpp rhombus.h trapezoid.cpp trapezoid.h
sanitize:
	g++ main.cpp figure.h rectangle.cpp rectangle.h rhombus.cpp rhombus.h trapezoid.cpp trapezoid.h -fno-omit-frame-pointer -fsanitize=address
clean:
	rm a.out *gch