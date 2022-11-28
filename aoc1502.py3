r = 0
rr = 0
with open('1502.0') as file:
	for line in file:
		l, w, h = [int(_) for _ in line.split('x')]
		# print(l, w, h)

		# part 1
		surf = l * w + w * h + h * l
		side = min(l * w, w * h, h * l)
		temp = 2 * surf + side
		r += temp

		# part 2
		side = max(l, w, h)
		peri = 2 * ((l + w + h) - side)
		temp = l * w * h + peri
		rr += temp

print("Star 1:", r)
print("Star 2:", rr)
