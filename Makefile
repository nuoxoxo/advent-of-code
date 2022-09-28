#* ************************************************************************** *#
#*                                                                            *#
#*                            \\             #`#``                            *#
#*                            ~\o o_       0 0\                               *#
#*                            # \__)      (u  ); _  _                         *#
#*                     # \# \#  #           \  \# \# \                        *#
#*                    #(   . . )            (         )\                      *#
#*                   #  \_____#              \_______#  \                     *#
#*                       []  []               [[] [[]    *.                   *#
#*                       []] []]              [[] [[]                         *#
#*                                                                            *#
#* ****************************************************************** .py *** *#

# comp	:=	c++ -Wall -Werror -Wextra -std=c++98
comp	:=	g++ -std=c++11

rmv	:=	rm -rf
name	:=	out


### Modify the src
src	:=	aoc2101_sonar.cpp
src	:=	aoc2101_sonar_old.cpp
src	:=	aoc2102_dive.cpp
src	:=	aoc2103_binary.cpp
src	:=	aoc2104_bingo.cpp


bud	:=	$(src:.cpp=.o)

%.o	:	%.cpp
		@#@ echo "compiling [$^] "
		@ $(comp) -c $^ -o $@


### Modify the last line
$(name)	:	$(bud)
		@#@ echo "compiling [$@] "
		@ $(comp) $^ -o $@
		@#@ ./out < aoc2101.0
		@#@ ./out < aoc2101.0
		@#@ ./out < aoc2102.0
		@#@ ./out < aoc2103.0
		@ ./out < aoc2104.0
		@ make f


all	:	$(name)

clean	:
		@ $(rmv) $(bud)

fclean	:	clean
		@ $(rmv) $(name) a.out

f	:	fclean
re	:	f all
.PHONY	:	fclean clean all re f
