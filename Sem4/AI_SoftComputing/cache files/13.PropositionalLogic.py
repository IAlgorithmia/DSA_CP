class PropositionalLogic:
    def __init__(self):
        pass

    def negate(self, p):
        return not p

    def conjunction(self, p, q):
        return p and q

    def disjunction(self, p, q):
        return p or q

    def implication(self, p, q):
        return (not p) or q

    def biconditional(self, p, q):
        return (p and q) or ((not p) and (not q))

# Example usage
logic = PropositionalLogic()
p = True
q = False

print("Negation of p:", logic.negate(p))
print("Conjunction of p and q:", logic.conjunction(p, q))
print("Disjunction of p and q:", logic.disjunction(p, q))
print("Implication of p implies q:", logic.implication(p, q))
print("Biconditional of p and q:", logic.biconditional(p, q))
