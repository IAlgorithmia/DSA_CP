# function to convert to subscript
def get_sub(x):
	normal = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+-=()"  
	sub_s = "ₐ₈CDₑբGₕᵢⱼₖₗₘₙₒₚQᵣₛₜᵤᵥwₓᵧZₐ♭꜀ᑯₑբ₉ₕᵢⱼₖₗₘₙₒₚ૧ᵣₛₜᵤᵥwₓᵧ₂₀₁₂₃₄₅₆₇₈₉₊₋₌₍₎"
	res = x.maketrans(''.join(normal), ''.join(sub_s))
	return x.translate(res)

# display subscript
string = 'H{}O+O{}'.format(get_sub('2'),get_sub('2'))
print(len(string), string) #H₂SO₄

