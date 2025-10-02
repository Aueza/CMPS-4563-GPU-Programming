a = [x for x in range(4096)]
print(a[0], a[4095])

b = [x + 4095 for x in range(4096)]
print(b[0], b[4095])

c = []

for i in range(4096):
    c.append(a[i] * b[i])

print(c[0], c[4095])

sum = 0
for i in range(4096):
    sum += c[i]
print(sum)
