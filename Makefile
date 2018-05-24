all:
	gcc -c -Wall -Werror -fpic -I/usr/include/libxml2 -lxml2  xmlx.c
	gcc -shared -o libxmlx.so xmlx.o
	cp libxmlx.so /usr/lib/

	gcc -L/usr/lib/ -Wall -o test -lxmlx -I/usr/include/libxml2 -lxml2 main.c
 

