##
## EPITECH PROJECT, 2025
## bsarcade
## File description:
## Makefile
##

LIB_SRC			=	lib/foo.cpp	\
					lib/bar.cpp	\
					lib/baz.cpp	\

LIB_OBJ			=	$(LIB_SRC:.cpp=.so)

SRC				=	src/DLLoader.cpp	\

OBJ				=	$(SRC:.cpp=.o)

MAIN_SRC		=	src/main.cpp		\

MAIN_OBJ		=	$(MAIN_SRC:.cpp=.o)

INCLUDES		=	-I./src -I./lib

CXXFLAGS		+=	-std=c++20 -Wall -Wextra -Werror $(INCLUDES)

CC				=	g++

NAME			=	bsarcade

%.so : %.cpp
	$(CC) $(CXXFLAGS) -shared -o $@ -fPIC $<

all:	$(NAME)

$(NAME):	$(LIB_OBJ) $(OBJ) $(MAIN_OBJ)
	$(CC) $(CXXFLAGS) -o $(NAME) $(OBJ) $(MAIN_OBJ) -ldl

clean:
	rm -f lib/libfoo.so
	rm -f lib/libbar.so
	rm -f lib/libbaz.so
	rm -f vgcore*

fclean: clean
	rm -f main $(LIB_OBJ) $(OBJ) $(MAIN_OBJ)

re: fclean all
