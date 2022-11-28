with open('1501.0') as f:
	for s in f:
		r = 0
		rr = 0
		ok = False
		for i in range(len(s)):
			c = s[i]
			if c == '(':
				r += 1
			if c == ')':
				r -= 1
			if r == -1 and not ok:
				rr = i
				ok = True
print("Star 1:", r)
print("Star 2:", rr)
