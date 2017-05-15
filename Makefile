main: *.cpp
	g++ *.cpp -g --std=c++11 -o showcasecpp -w -Werror -lpthread

clean:
	rm showcasecpp