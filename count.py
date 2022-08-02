import glob
files = glob.glob("include/*")

lines = 0


for i in files:
    if i != "include/json.hpp":
        with open(i) as f:
            lines += len(f.read().split('\n'))
print(lines)
