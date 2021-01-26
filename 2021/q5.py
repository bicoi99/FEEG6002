#!/usr/bin/python3
import numpy as np
import matplotlib.pyplot as plt

with open("2021/data.txt", "r") as f:
    lines = f.readlines()

n = len(lines)
t = np.zeros(n)
p1 = np.zeros(n)
p2 = np.zeros(n)

for i in range(n):
    line = lines[i].strip()
    t[i], p1[i], p2[i] = list(map(float, line.split("\t")))

plt.plot(t, p1, label="rabbits")
plt.plot(t, p2, label="foxes")
plt.title("$a=0.7,c=0.007,b=1,p_1(0)=70,p_2(0)=50,dT=0.001$")
plt.ylabel("$p_1,p_2$")
plt.xlabel("$t$")
plt.legend(loc='lower right')
plt.grid(True)
# plt.savefig("2021/figure1.png")
plt.show()
