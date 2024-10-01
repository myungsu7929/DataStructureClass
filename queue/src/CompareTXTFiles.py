def compare_files(file1_path, file2_path):
    with open(file1_path, 'r', encoding='utf-8') as file1, open(file2_path, 'r', encoding='utf-8') as file2:
        lines1 = file1.readlines()
        lines2 = file2.readlines()

    differences = []

    # Compare line by line
    max_lines = max(len(lines1), len(lines2))
    for i in range(max_lines):
        line1 = lines1[i].strip() if i < len(lines1) else ''
        line2 = lines2[i].strip() if i < len(lines2) else ''
        
        if line1 != line2:
            differences.append(i + 1)  # Line numbers start from 1

    return differences

file1_path = 'output_Queue.txt'
file2_path = 'output_Queue_MS.txt'

differences = compare_files(file1_path, file2_path)

if differences:
    print("The files differ at the following lines:")
    for line_num in differences:
        print(f"Line {line_num}")
else:
    print("The files are identical.")
