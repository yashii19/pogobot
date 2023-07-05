import matplotlib.pyplot as plt



# EXPERIENCE 1 

x = [1, 64, 200, 380]

y1 = [1139,4045,10259,18481]
y2 = [1139,4045,10259,18481]
y3 = [1139,4045,10259,18481]
y4 = [1139,4045,10259,18481]
y5 = [1139,4045,10259,18481]
y6 = [1139,4047,10259,18481]
y7 = [1139,4045,10259,18481]
y8 = [1139,4045,10259,18481]
y9 = [1139,4045,10259,18484]
y10 = [1142,4045,10262,18481]

plt.plot(x, y1, label="experience=1")
plt.plot(x, y2, label="experience=2")
plt.plot(x, y3, label="experience=3")
plt.plot(x, y4, label="experience=4")
plt.plot(x, y5, label="experience=5")
plt.plot(x, y6, label="experience=6")
plt.plot(x, y7, label="experience=7")
plt.plot(x, y8, label="experience=8")
plt.plot(x, y9, label="experience=9")
plt.plot(x, y10, label="experience=10")
plt.title('Message emission time of a Pogobot\n[IRPOWER=2,PROTOCOLE=5GhZ, FQ=30Hz]')






# Afficher le graphique

plt.xlim(0, 400)
plt.ylim(0, 20000)
plt.xlabel('Emission time (in ms)')
plt.ylabel('Size of the sent message (in octets)')
plt.legend(loc='upper right')
plt.show()