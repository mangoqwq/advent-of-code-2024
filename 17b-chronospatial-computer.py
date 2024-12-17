import z3

regA = input()
regB = input()
regC = input()
input()
program = input()[9:].split(',')

def iterate(ub):
	solver = z3.Solver()
	A = z3.BitVec('A', 49)

	for i, x in enumerate(program):
		B = ((A >> (3 * i)) % 8) ^ 5
		solver.add(((B ^ 6 ^ (A >> (3 * i + B))) % 8 == x))
	solver.add(A < ub)

	if solver.check() == z3.sat:
		return (True, solver.model()[A].as_long())
	else:
		return (False, -1)
	
sol = int(1e18)
while True:
	ok, nxt = iterate(sol)
	if not ok:
		break
	print(nxt)
	sol = nxt
print(f"{sol=}")
