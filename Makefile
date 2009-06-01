main: regex.so

	cp regex.h /usr/local/include
	cp libregex.so /etc/lib/libregex.so 

regex.so : regex.cpp
	g++ -fPIC -c -Wall regex.cpp 
	g++ -shared -Wl -o libregex.so regex.o 

clean:
	mv /usr/local/include/regex.h
	mv /etc/lib/libregex.so 
