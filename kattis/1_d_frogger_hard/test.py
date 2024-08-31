import random

def generate_test_case(size, filename):
    # Generate random non-zero integers between -6 and 6
    numbers = [random.randint(-200, 200) for _ in range(size)]

    with open(filename, 'w') as file:
        # Write the size of the list first
        file.write(f"{size}\n")
        # Write the numbers space-separated in a single line
        file.write(" ".join(map(str, numbers)) + "\n")

# generate_test_case(100, 'test_case_1000.txt')
# generate_test_case(1000, 'test_case_1000.txt')
generate_test_case(10000, 'test_case_10000.txt')
