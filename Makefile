comp	:=	c++ -std=c++17
name	:=	out
rmv	:=	rm -f
pre	:=	_inputs/
src	:=	2301.cc
all	:	$(name)
$(name)	:	$(src)
		@ $(comp) $^ -o $@
		@ ./$(name) < $(pre)01.in

test	:	all
		@ echo "\ntest"
		@ ./$(name) < $(pre)01.1
		@ make f

clean	:
		@ $(rmv) $(name)

fclean	:	clean
		@ $(rmv) out *.out

f	:	fclean
re	:	f all
.PHONY	:	fclean clean f all re
