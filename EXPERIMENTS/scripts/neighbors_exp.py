import matplotlib.pyplot as plt


x = [2,6,12]

y1 = [471.7902, 415.125,87.3986,31.0758]
y2 = [718.0804,357.6683,450.677,17419.6381]
y3 = [1189.2429, 1391.4388,9530.9127,100000000]

# EXPERIENCE [p_emission=0.1]
p1 = [471.7902, 718.0804, 1189.2429]
p1_std = [312.6201295, 204.6186537, 627.065129]

# EXPERIENCE [p_emission=0.16]
p2 = [415.125, 357.6683, 1391.4388]
p2_std = [323.0417621, 178.1952456, 576.0411355]

# EXPERIENCE [p_emission=0.5]
p3 = [87.3986,450.677, 9530.9127]
p3_std = [47.7870527, 306.2347421, 4434.46407]

# EXPERIENCE [p_emission=0.9]
p4 = [31.0758, 17419.6381, 100000000]
p4_std = [11.36960661, 18380.10892, 0]

#--------------------------------------------------------

"""

# EXPERIENCE [p_emission=0.1, nb_neighbors=2]
exp1_1 = [691.657, 158.785, 361.377, 825.625, 328.096, 25.171, 391.151, 1054.477, 558.705, 322.858]
# EXPERIENCE [p_emission=0.1, nb_neighbors=6]
exp1_2 = [653.047, 623.999, 984.224, 491.660, 887.942,  887.942, 688.263, 326.624, 887.898, 749.205, ]
# EXPERIENCE [p_emission=0.1, nb_neighbors=12]
exp1_3 = [526.763, 2306.320, 786.444, 814.121, 1053.787, 1409.165,  1121.521, 753.011, 849.414,  2271.883]
# EXPERIENCE [p_emission=0.16, nb_neighbors=2]
exp2_1 = [359.983, 294.506,  157.270, 96.671, 1251.722, 428.743, 255.989, 556.022, 426.472, 323.872, ]
# EXPERIENCE [p_emission=0.16, nb_neighbors=6]
exp2_2 = [193.311, 455.032, 423.277, 786.626, 394.550, 223.801, 291.978, 192.378, 355.287, 257.378]
# EXPERIENCE [p_emission=0.16, nb_neighbors=12]
exp2_3 = [978.587, 1319.310, 1910.760, 1217.893, 880.642, 1681.982, 1383.209, 1150.490, 715.381, 2676.134, ]
# EXPERIENCE [p_emission=0.5, nb_neighbors=2]
exp3_1 = [62.837,92.468,61.577,125.697,124.666,166.331,25.596,56.096,130.555,28.163]
# EXPERIENCE [p_emission=0.5, nb_neighbors=6]
exp3_2 = [222.569,96.137,589.844,625.966,158.960,922.250,285.093,129.385,817.753,658.813]
# EXPERIENCE [p_emission=0.5, nb_neighbors=12]
exp3_3 = [13757.704, 14550.748, 2735.793, 14938.420, 7837.316, 12932.017, 4855.279, 4855.279, ]
# EXPERIENCE [p_emission=0.9, nb_neighbors=2]
exp4_1 = [63.296,28.818,26.736,27.373,27.430,25.442,29.318,27.562,27.468,27.315, 9023.975, 9822.596]
# EXPERIENCE [p_emission=0.9, nb_neighbors=6]
exp4_2 = [24338.762,3461.912,16608.058,9552.316,5021.834,66207.288,8720.180,19521.578,7056.535,13707.918]
# EXPERIENCE [p_emission=0.9, nb_neighbors=12]
exp4_3 = [100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000]

exp1 = [exp1_1,exp1_2,exp1_3]
exp2 = [exp2_1, exp2_2, exp2_3]
exp3 = [exp3_1,exp3_2,exp3_3]
exp4 = [exp4_1, exp4_2, exp4_3]
plt.boxplot(exp1, labels=["nb_neighbors=2", "nb_neighbors=6", "nb_neighbors=12"])
plt.boxplot(exp2, labels=["nb_neighbors=2", "nb_neighbors=6", "nb_neighbors=12"])
plt.boxplot(exp3, labels=["nb_neighbors=2", "nb_neighbors=6", "nb_neighbors=12"])
plt.boxplot(exp4, labels=["nb_neighbors=2", "nb_neighbors=6", "nb_neighbors=12"])

"""

#GRAPH 1 - mean + std with LOG y=10**5
"""
plt.errorbar(x, p1, yerr=p1_std, capsize=5, marker='o', linestyle="None", label="p_send=0.1")
plt.errorbar(x, p2, yerr=p2_std, capsize=5, marker='o', linestyle="None", label="p_send=0.16")
plt.errorbar(x, p3, yerr=p3_std, capsize=5, marker='o', linestyle="None", label="p_send=0.5")
plt.errorbar(x, p4, yerr=p4_std, capsize=5, marker='o', linestyle="None", label="p_send=0.9")
plt.yscale('log')
plt.ylim(1, 10**5)
plt.xlim(0, 15)

plt.title('N-to-N communication efficiency\nrobots=[4][...],send_mode=*,ir_power=2,clock=30Hz,msg_len=64')
plt.xlabel('number of neighbours')
plt.ylabel('time to full discovery (milliseconds)')
plt.legend(loc='upper left')
plt.show()
"""

#GRAPH 2 - mean + std with y=2000
"""
plt.errorbar(x, p1, yerr=p1_std, capsize=5, marker='o', linestyle="None", label="p_send=0.1")
plt.errorbar(x, p2, yerr=p2_std, capsize=5, marker='o', linestyle="None", label="p_send=0.16")
plt.errorbar(x, p3, yerr=p3_std, capsize=5, marker='o', linestyle="None", label="p_send=0.5")
plt.errorbar(x, p4, yerr=p4_std, capsize=5, marker='o', linestyle="None", label="p_send=0.9")
plt.ylim(1, 2000) 

plt.title('N-to-N communication efficiency\nrobots=[4][...],send_mode=*,ir_power=2,clock=30Hz,msg_len=64')
plt.xlabel('number of neighbours')
plt.ylabel('time to full discovery (milliseconds)')
plt.legend(loc='upper left')
plt.show()
"""

#GRAPH3 - mean + std with y=10**5
"""
plt.errorbar(x, p1, yerr=p1_std, capsize=5, marker='o', linestyle="None", label="p_send=0.1")
plt.errorbar(x, p2, yerr=p2_std, capsize=5, marker='o', linestyle="None", label="p_send=0.16")
plt.errorbar(x, p3, yerr=p3_std, capsize=5, marker='o', linestyle="None", label="p_send=0.5")
plt.errorbar(x, p4, yerr=p4_std, capsize=5, marker='o', linestyle="None", label="p_send=0.9")

piolt.ylim(1, 10**4.5) 
plt.title('N-to-N communication efficiency\nrobots=[4][...],send_mode=*,ir_power=2,clock=30Hz,msg_len=64')
plt.xlabel('number of neighbours')
plt.ylabel('time to full discovery (milliseconds)')
plt.legend(loc='upper left')
plt.show()
"""

#GRAPH4 - boxplot with LOG y=10**5
"""
data=[y1,y2,y3]
plt.boxplot(data, labels=["2", "6", "12"])

plt.yscale('log')
plt.ylim(1, 10**5)
plt.title('N-to-N communication efficiency\nrobots=[4][...],send_mode=*,ir_power=2,clock=30Hz,msg_len=64')
plt.xlabel('number of neighbours')
plt.ylabel('time to full discovery (milliseconds)')
plt.legend(loc='upper left')
plt.show()
"""

#GRAPH5 - boxplot with y=2000

data=[y1,y2,y3]
plt.boxplot(data, labels=["2", "6", "12"])

plt.ylim(1, 2000) 
plt.title('N-to-N communication efficiency\nrobots=[4][...],send_mode=*,ir_power=2,clock=30Hz,msg_len=64')
plt.xlabel('number of neighbours')
plt.ylabel('time to full discovery (milliseconds)')
plt.legend(loc='upper left')
plt.show()

#GRAPH6 - boxplot with y=10**5

data=[y1,y2,y3]
plt.boxplot(data, labels=["2", "6", "12"])

plt.ylim(1, 10**4.5) 
plt.title('N-to-N communication efficiency\nrobots=[4][...],send_mode=*,ir_power=2,clock=30Hz,msg_len=64')
plt.xlabel('number of neighbours')
plt.ylabel('time to full discovery (milliseconds)')
plt.legend(loc='upper left')
plt.show()
