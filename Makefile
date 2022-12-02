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
src	:=	aoc2101_sonar_long.cpp
src	:=	aoc2102_dive.cpp
src	:=	aoc2103_binary.cpp
src	:=	aoc2104_bingo.cpp
src	:=	aoc2105_venture.cpp
src	:=	aoc2106_lantern.cpp
src	:=	aoc2107_crab_brute.cpp
src	:=	aoc2107_crab.cpp
#
src	:=	aoc2101_sonar.cpp
src	:=	aoc2001_sum.cpp
src	:=	aoc2003_trees.cpp


bud	:=	$(src:.cpp=.o)

%.o	:	%.cpp
		@#@ echo "compiling [$^] "
		@ $(comp) -c $^ -o $@


### Modify the last line
$(name)	:	$(bud)
		@ $(comp) $^ -o $@
		@ ./out < 2003.0
		@ echo "test" && echo ""
		@ ./out < test
		@#@ ./out < aoc2101.1; ./out < aoc2101.0
		@#@ ./out < aoc2001.1; ./out < aoc2001.0
		@#@ ./out < aoc2101.0
		@#@ ./out < aoc2102.0
		@#@ ./out < aoc2103.0
		@#@ ./out < aoc2104.0
		@#@ ./out < aoc2105.0
		@#@ ./out < aoc2106.0
		@#@ ./out < aoc2107.0
		@ make f


all	:	$(name)

clean	:
		@ $(rmv) $(bud)

fclean	:	clean
		@ $(rmv) $(name) a.out

f	:	fclean
re	:	f all
.PHONY	:	fclean clean all re f
