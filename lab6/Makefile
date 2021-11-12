ALL:
	g++ item.cpp main.cpp rectangle.cpp tallocation_block.cpp tvector.cpp Iter.h Tree.h TreeNode.h item.h rectangle.h tallocation_block.h tvector.h -Wall -Wextra
sanitize:
	g++ item.cpp main.cpp rectangle.cpp tallocation_block.cpp tvector.cpp Iter.h Tree.h item.h rectangle.h tallocation_block.h tvector.h -fno-omit-frame-pointer -fsanitize=address
clean:
	rm a.out *gch