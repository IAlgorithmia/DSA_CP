from PIL import Image
img = Image.open(r"E:\Academics\College Academics\Programming\Sem2\Python\Images\TheImage.jpg").convert("RGB")
width, height = img.size
print(img.size)
for y in range(height):
    for x in range(width):
        r, g, b = img.getpixel((x, y))
        print(f"The RGB values for pixel {x}, {y} are : Red = {r}, Green = {g}, Blue = {b}")