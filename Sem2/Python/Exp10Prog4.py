from PIL import Image
gray_image = Image.open(r"E:\Academics\College Academics\Codes\Sem2\Python\Images\3.jpg").convert("L")
binary_threshold = 200
binary_image = gray_image.point(lambda pixel: 0 if pixel < binary_threshold else 255, "1")
gray_image.show()
binary_image.show()
# gray_image.save("gray_image_saved.jpg")
# binary_image.save("binary_image_saved.jpg")