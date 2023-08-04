import matplotlib.pyplot as plt

y = [1, 64, 200, 380]

x1 = [1.1393, 4.0452, 10.2593, 18.4813]
x2 = [0.4022, 1.145, 2.706, 4.7703]

# Standard deviation values for y1 and y2
x1_std = [0.9486832981, 0.632455532, 0.9486832981, 0.9486832981]  # Replace with your actual standard deviation values for y1
x2_std = [0.632455532, 0, 0, 0.9486832981]  # Replace with your actual standard deviation values for y2



#GRAPH1 - old vs new protocole
#plt.errorbar(x1, y, xerr=x1_std, capsize = 10, fmt="o", label="protocole=3.5MHz(beta1)")
#plt.errorbar(x2, y, xerr=x2_std, capsize = 10, fmt="o", label="protocole=3,5MHz(final)")
#plt.title('Payload size vs time cost \nsend_mode=*,ir_power=2,clock=30Hz')

#GRAPH2 - new protocole
plt.errorbar(x2, y, xerr=x2_std, capsize = 10, fmt="o")
plt.title('Payload size vs time cost \nsend_mode=*,ir_power=2,clock=30Hz')


plt.xlim(0, 8)
plt.ylim(0, 400)
plt.xlabel('Average mean of Sending time (in ms)')
plt.ylabel('Size of the sent message (in octets)')
plt.legend(loc='upper left')
plt.show()