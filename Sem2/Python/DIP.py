from PIL import Image, ImageFilter, ImageDraw, ImageFont
img = Image.open(r"E:\Academics\College Academics\Programming\Sem2\Python\Images\3.jpg")
img.show()
print(img.height)
print(img.width)
print(img.size)
print(img.format)
new_size = (200, 200)
img.thumbnail(new_size)
img.save("NewImage.png")
img.show()
rotated_image = img.rotate(45)
rotated_image.show()
area = (180, 630, 330, 700)
cropped_image = img.crop(area)
cropped_image.show()
img = Image.new("RGB", new_size, "rgb(5, 250, 70)")
img.show()
crop_default = (0, 0, 800, 800)
img1 = Image.open(r"E:\Academics\College Academics\Programming\Sem2\Python\Images\1.jpg")
img2 = Image.open(r"E:\Academics\College Academics\Programming\Sem2\Python\Images\2.jpg")
new_img1 = img1.crop(crop_default)
new_img2 = img2.crop(crop_default)
new_img = Image.blend(new_img1, new_img2, 0.5)
new_img.show()
img = Image.open(r"E:\Academics\College Academics\Programming\Sem2\Python\Images\3.jpg")
img.filter(ImageFilter.BoxBlur(50)).show()
draw = ImageDraw.Draw(img)
myfont = ImageFont.truetype("arial.ttf", 50)
points = (200, 200)
string = "I'm Sexy and I know it"
color = "white"
draw.text(points, string, color, font = myfont)
img.show()