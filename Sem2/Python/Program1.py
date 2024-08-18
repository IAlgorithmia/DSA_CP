import math
def temperature_converter(temperature, from_unit, to_unit):
    try :
        mytemp = math.floor(temperature)
        temp_list = ['K', 'C', 'F']
        if (str(mytemp).isdigit() and ((from_unit in temp_list) and (to_unit in temp_list))):
            match (from_unit):
                case 'C':
                    match (to_unit):
                        case 'C':
                            result = temperature
                        case 'K':
                            result = temperature + 273.15
                        case 'F':
                            result = temperature*(9/5) + 32
                case 'F':
                    match (to_unit):
                        case 'C':
                            result = (temperature - 32)*(5/9)
                        case 'K':
                            result = (temperature + 459.67)*(5/9)
                        case 'F':
                            result = temperature
                case 'K':
                    match (to_unit):
                        case 'C':
                            result = temperature - 273.15
                        case 'K':
                            result = temperature
                        case 'F':
                            result = temperature*(9/5) - 459.67
        else:
            result = None
    except : 
        result = None
    return result
answer = temperature_converter("hi", 'C', 'K')
if (answer != None):
    print(answer)
else:
    print("Wrong Inputs!")