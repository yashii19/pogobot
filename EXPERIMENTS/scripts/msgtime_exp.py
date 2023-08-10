import matplotlib.pyplot as plt

x = [1, 64, 200, 380]

y1 = [1.1393, 4.0452, 10.2593, 18.4813]
y2 = [0.4022, 1.145, 2.706, 4.7703]

# Standard deviation values for y1 and y2
y1_std = [0.9486832981, 0.632455532, 0.9486832981, 0.9486832981]  
y2_std = [0.632455532, 0, 0, 0.9486832981] 

# GRAPH1 - old vs new protocol
plt.errorbar(x, y1, yerr=y1_std, capsize=10, fmt="o", color="orange", label="Protocol=3.5MHz (beta1)")
plt.errorbar(x, y2, yerr=y2_std, capsize=10, fmt="o", color='blue', label="Protocol=3.5MHz (final)")
plt.title('Payload size vs time cost\nsend_mode=*, ir_power=2, clock=30Hz')

plt.xlim(0, 400)
plt.xticks(range(50, 401, 50))
plt.ylim(0, 25)
plt.yticks([0.0, 5.0, 10.0, 15.0, 20.0])
plt.xlabel('Payload sent (size in bytes)')
plt.ylabel('Sending time (milliseconds)')
plt.legend(loc='upper left')
plt.grid(True)
plt.show()

# GRAPH2 - new protocol
plt.errorbar(x, y2, yerr=y2_std, capsize=10, fmt="o", color='blue')
plt.title('Payload size vs time cost\nsend_mode=*, ir_power=2, clock=30Hz')

plt.xlim(0, 400)
plt.xticks(range(50, 401, 50))
plt.ylim(0, 8)
plt.yticks([1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0])
plt.xlabel('Payload sent (size in bytes)')
plt.ylabel('Sending time (milliseconds)')
plt.grid(True)
plt.show()
