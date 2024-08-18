class Disk:
    def use(self):
        print("To Write")
class File:
    def use(self):
        print("To read")
class Storage(File , Disk):
    def impl(self):
        super().use()
str = Storage()
str.impl()