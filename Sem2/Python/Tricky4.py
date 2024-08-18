class MOE:
    def intro(self):
        print("MOE")
class NITKKR(MOE):
    def intro(self):
        print("NITKKR")
class COE(NITKKR):
    pass
Department = COE()
Department.intro()