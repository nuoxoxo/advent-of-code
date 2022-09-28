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

comp	:=	c++ -Wall -Werror -Wextra -std=c++98
comp	:=	g++ -std=c++11
#comp	:=	c++ -Wall -Werror -Wextra -std=c++98
rmv	:=	rm -rf
name	:=	out

# Modify the src
src	:=	aoc2101_sonar.cpp
src	:=	aoc2101_sonar_old.cpp




bud	:=	$(src:.cpp=.o)

%.o	:	%.cpp
		@ echo "compiling [$^] "
		@ $(comp) -c $^ -o $@

# Modify the last line
$(name)	:	$(bud)
		@ echo "compiling [$@] "
		@ $(comp) $^ -o $@
		@ ./out < aoc2101_sonar.0
		@ make f

all	:	$(name)

clean	:
		@ $(rmv) $(bud)

fclean	:	clean
		@ $(rmv) $(name) a.out

f	:	fclean
re	:	f all
.PHONY	:	fclean clean all re f
