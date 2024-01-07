import random

for length in range(1, 11):
    random_array = [random.randint(0, 10) for _ in range(length)]
    print(f"Array of length {length}: {random_array}")
