class Library:
    def __init__(self):
        self.number_of_books = 0
        self.books = []
    def addbooks(self, book):
        self.books.append(book)
        self.number_of_books += 1
    def display(self):
        print("Following books are available : ")
        for i in range(self.number_of_books):
            print(f"The book name is {self.books[i]}")
        print(f"The total number of books is {self.number_of_books}")
object = Library()
num = int(input("Enter the numer of books you want to add : "))
for i in range(num):
    name = input("Enter the book's name : ")
    object.addbooks(name)
object.display()