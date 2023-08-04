import numpy as np
import matplotlib.pyplot as plt

# Création du tableau de valeurs 2D
x = np.arange(-15, 16)
y = np.arange(-15, 16)


#EXP 16 octets
values1 = np.zeros((31,31))
values2 = np.zeros((31,31))

values1[5] = [0,0,0,0,0,0,0,0,0,0,0,10,10,10,50,10,10,10,0,0,0,0,0,0,0,0,0,0,0,0,0]
values2[5] = [0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0]

values1[6] = [0,0,0,0,0,0,0,0,0,0,0,50,30,90,90,90,70,90,10,10,0,0,0,0,0,0,0,0,0,0,0]
values2[6] = [0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0]

values1[7] = [0,0,0,0,0,0,0,0,0,0,10,90,90,100,100,100,100,100,90,30,10,0,0,0,0,0,0,0,0,0,0]
values2[7] = [0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0]

values1[8] = [0,0,0,0,0,0,0,0,0,0,50,100,100,100,100,100,100,100,100,90,50,30,10,0,0,0,0,0,0,0,0]
values2[8] = [0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0]

values1[9] = [0,0,0,0,0,0,0,0,0,10,90,100,100,100,100,100,100,100,100,100,90,50,30,0,0,0,0,0,0,0,0]
values2[9] = [0,0,0,0,0,0,0,0,0,1,1,2,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0]

values1[10] = [0,0,0,0,0,0,0,0,10,30,100,100,100,100,100,100,100,100,100,100,100,90,50,0,0,0,0,0,0,0,0]
values2[10] = [0,0,0,0,0,0,0,0,1,2,2,2,2,1,1,1,1,1,2,2,2,2,2,0,0,0,0,0,0,0,0]

values1[11] = [0,0,0,0,0,0,0,30,90,50,100,100,100,100,100,100,100,100,100,100,100,100,90,30,0,0,0,0,0,0,0]
values2[11] = [0,0,0,0,0,0,0,1,1,2,2,2,2,2,1,1,1,2,2,2,2,2,2,1,0,0,0,0,0,0,0]

values1[12] = [0,0,0,0,0,0,10,90,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,90,30,0,0,0,0,0,0]
values2[12] = [0,0,0,0,0,0,1,1,1,2,1,2,2,2,1,1,1,2,2,2,2,2,2,1,1,0,0,0,0,0,0]

values1[13] = [0,0,0,0,0,0,30,100,100,100,100,100,100,100,0,0,0,100,100,100,100,100,100,100,70,0,0,0,0,0,0]
values2[13] = [0,0,0,0,0,0,1,1,1,2,2,2,2,2,0,0,0,2,2,2,2,2,1,1,1,0,0,0,0,0,0]

values1[14] = [0,0,0,0,0,0,90,100,100,100,100,100,100,0,0,0,0,0,100,100,100,100,100,100,90,0,0,0,0,0,0]
values2[14] = [0,0,0,0,0,0,1,1,1,1,2,2,2,0,0,0,0,0,2,2,2,1,1,1,1,0,0,0,0,0,0]

values1[15] = [0,0,0,0,0,10,90,100,100,100,100,100,90,0,0,0,0,0,90,100,100,100,100,100,90,10,0,0,0,0,0]
values2[15] = [0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,2,2,2,1,1,1,1,1,0,0,0,0,0]

values1[16] = [0,0,0,0,0,10,90,100,100,100,100,100,100,0,0,0,0,0,100,100,100,100,100,100,90,10,0,0,0,0,0]
values2[16] = [0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,2,2,2,1,1,1,1,1,0,0,0,0,0]

values1[17] = [0,0,0,0,0,10,90,100,100,100,100,100,100,100,0,0,0,100,100,100,100,100,100,100,70,10,0,0,0,0,0]
values2[17] = [0,0,0,0,0,1,1,1,1,1,1,2,2,2,0,0,0,2,2,2,1,1,1,1,1,1,0,0,0,0,0]

values1[18] = [0,0,0,0,0,10,50,100,100,100,100,100,100,100,100,50,100,100,100,100,100,100,100,90,30,0,0,0,0,0,0]
values2[18] = [0,0,0,0,0,1,1,1,1,1,2,2,2,2,1,1,1,2,2,2,2,1,1,1,1,0,0,0,0,0,0]

values1[19] = [0,0,0,0,0,0,10,90,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,50,0,0,0,0,0,0,0]
values2[19] = [0,0,0,0,0,0,1,1,1,2,2,2,2,2,1,1,1,2,2,2,2,2,1,1,0,0,0,0,0,0,0]

values1[20] = [0,0,0,0,0,0,10,90,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,50,0,0,0,0,0,0,0]
values2[20] = [0,0,0,0,0,0,1,1,1,2,2,2,2,2,1,1,1,2,2,2,2,2,1,1,0,0,0,0,0,0,0]

values1[21] = [0,0,0,0,0,0,0,30,90,100,100,100,100,100,100,100,100,100,100,100,100,100,50,0,0,0,0,0,0,0,0]
values2[21] = [0,0,0,0,0,0,0,1,1,2,2,2,2,1,1,1,1,2,2,2,2,2,1,0,0,0,0,0,0,0,0]

values1[22] = [0,0,0,0,0,0,0,0,10,50,100,100,100,100,100,100,100,100,100,100,100,90,0,0,0,0,0,0,0,0,0]
values2[22] = [0,0,0,0,0,0,0,0,1,1,2,2,2,1,1,1,1,1,2,2,2,1,0,0,0,0,0,0,0,0,0]

values1[23] = [0,0,0,0,0,0,0,0,0,10,90,100,100,100,100,100,100,100,100,100,100,50,0,0,0,0,0,0,0,0,0]
values2[23] = [0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0]

values1[24] = [0,0,0,0,0,0,0,0,0,0,50,100,100,100,100,100,100,100,100,100,90,10,0,0,0,0,0,0,0,0,0]
values2[24] = [0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0]

values1[25] = [0,0,0,0,0,0,0,0,0,0,10,50,90,100,100,100,100,100,100,100,30,0,0,0,0,0,0,0,0,0,0]
values2[25] = [0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0]

values1[26] = [0,0,0,0,0,0,0,0,0,0,0,10,10,90,70,100,100,90,100,70,0,0,0,0,0,0,0,0,0,0,0]
values2[26] = [0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0]

values1[27] = [0,0,0,0,0,0,0,0,0,0,0,0,0,30,30,30,10,90,20,10,0,0,0,0,0,0,0,0,0,0,0]
values2[27] = [0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0]


#GRAPH1 - 2d_exp64
heatmap1 = plt.imshow(values1, extent=[-15, 15, -15, 15], origin='lower', cmap='Reds')
cbar = plt.colorbar(heatmap1)
plt.title('\nPairwise communication 2D : reception efficiency \n     robots=[31][32],send_mode=*,ir_power=2,clock=30Hz,msg_len=64 \n')

#GRAPH2 - 2d_exp64_emission
#heatmap2 = plt.imshow(values2,extent=[-15.5, 15.5, -15.5, 15.5], origin='lower', cmap='Reds')
#cbar2 = plt.colorbar(heatmap2)
#plt.title('\nPairwise communication 2D : sensor overlap \n     robots=[31][32],send_mode=*,ir_power=2,clock=30Hz,msg_len=64 \n')




plt.xlabel('Distance en cm')
plt.ylabel('Distance en cm')

# Affichage de la figure
plt.show()
