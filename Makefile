comp	:=	c++ -std=c++17
name	:=	out
rmv	:=	rm -f
pre	:=	_inputs_/
src	:=	2301.cc
src	:=	2302.cc
all	:	$(name)
$(name)	:	$(src)
		@ $(comp) $^ -o $@
		@ ./$(name) < $(pre)02.in
		@#@ ./$(name) < $(pre)01.in

test	:	all
		@ echo "\n\n------\ntest\n------\n"
		@ ./$(name) < $(pre)02.test
		@#@ ./$(name) < $(pre)01.test
		@ make f

clean	:
		@ $(rmv) $(name)

fclean	:	clean
		@ $(rmv) out *.out

t		:	test

f	:	fclean
re	:	f all
.PHONY	:	fclean clean f all re
