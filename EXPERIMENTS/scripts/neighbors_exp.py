import matplotlib.pyplot as plt

#x = [0.1, 0.16, 0.5, 0.9]
x = [2,6,12]

# EXPERIENCE [robot=4,nb_neighbor=2,msg_len=64]
y1 = [471.7902, 415.125, 87.3986, 31.0758]

# EXPERIENCE [robot=4,nb_neighbor=6,msg_len=64]
y2 = [718.0804, 857.6683, 450.677, 17419.6381]

# EXPERIENCE [robot=4,nb_neighbor=12,msg_len=64]
y3 = [1189.2429, 3765.3, 9530.9127, 100000]


p1 = [471.7902, 718.0804, 1189.2429]

p2 = [415.125, 357.6683, 1391.4388]

p3 = [87.3986,450.677, 9530.9127]

p4 = [31.0758, 17419.6381, 100000000]

#--------------------------------------------------------

# GRAPH 1 : ROBOTS=[4]
#plt.plot(x, y1, label="nb_neighbor=2")
#plt.plot(x, y2, label="nb_neighbor=6")
#plt.plot(x, y3, label="nb_neighbor=12")
#plt.title('Neighbors Pogobot Communication \nrobot=[4], clock=30, msg_len=64')


#GRAPH 2
plt.plot(x, p1, label="p_send=0.1")
plt.plot(x, p2, label="p_send=0.16")
plt.plot(x, p3, label="p_send=0.5")
plt.plot(x, p4, label="p_send=0.9")
plt.title('N-to-N communication efficiency\nrobots=[4][...],send_mode=*,ir_power=2,clock=30Hz,msg_len=64')

# Mettre l'axe Y à une échelle logarithmique
#plt.yscale('log')

# Afficher le graphique
plt.xlim(0, 15)
plt.ylim(1, 10**4)  # Vous pouvez ajuster les limites de l'axe Y selon vos besoins
#plt.xlabel('probability of msg emission')
plt.xlabel('number of neighbours')
plt.ylabel('time to full discovery (milliseconds)')
plt.legend(loc='upper left')
plt.show()

