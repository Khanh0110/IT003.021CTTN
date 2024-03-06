import numpy as np

# Đọc dữ liệu từ file và lưu vào mảng
with open('songaunhien_1.txt', 'r') as file:
    # Đọc toàn bộ nội dung của file
    data = file.read()
    # Tách các số nguyên từ chuỗi dữ liệu và chuyển thành số nguyên
    numbers = [int(num) for num in data.split()]
numbers_array = np.array(numbers)
sorted_array = np.sort(numbers_array)
# Mở tập tin mới để ghi mảng đã sắp xếp
with open('sorted_1.txt', 'w') as file:
    for num in sorted_array:
        file.write(f"{num} ")  # Ghi số nguyên và một khoảng trắng sau mỗi số
