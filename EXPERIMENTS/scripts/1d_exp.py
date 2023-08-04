import matplotlib.pyplot as plt


x = [0, 0.5, 1,1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8, 8.5, 9,9.5]

# EXPERIENCE 1_OLD [robots=[6][4],send_mode=*,ir_power=2,clock=30Hz,msg_len=64]
y1_old = [50, 70, 50, 30, 30,50,70,90,100,100,100,90,50,10,0,0,0,0,0,0]

# EXPERIENCE 2_OLD [robots=[4][6],send_mode=*,ir_power=2,clock=30Hz,msg_len=64]
y2_old = [10,50,50,30,30,50,70,90,90,100,100,90,90,70,30,0,0,0,0]


# EXPERIENCE 1 [robots=[6][4],send_mode=*,ir_power=2,clock=30Hz,msg_len=64]
y1 = [70,70,100,100,100,100,100,100,100,100,100,100,100,100,90,30,10,0,0,0]

# EXPERIENCE 1_UPDATE0407 [robots=[6][4],send_mode=*,ir_power=2,clock=30Hz,msg_len=64]
y1_update = [70,100,100,100,100,100,100,100,100,100,100,100,100,100,90,30,10,0,0,0]


# EXPERIENCE 2 [robots=[6][4],send_mode=*,ir_power=2,clock=60Hz,msg_len=64]
y2 = [70,100,100,100,100,100,100,100,100,100,100,100,100,90,90,10,10,0,0,0]

# EXPERIENCE 3 [robots=[6][4],send_mode=*,ir_power=2,clock=120Hz,msg_len=64]
y3 = [70,100,100,100,100,100,100,100,100,100,100,100,90,90,50,10,0,0,0,0]

# EXPERIENCE 4 [robots=[6][4],send_mode=*,ir_power=2,clock=180Hz,msg_len=64]
y4 = [10,50,70,90,90,90,90,90,90,90,90,90,90,90,50,10,0,0,0,0]

# EXPERIENCE 5 [robots=[6][4],send_mode=*,ir_power=2,clock=240Hz,msg_len=64]
y5 = [0,0,0,0,10,50,50,50,50,50,50,50,50,30,20,10,0,0,0,0]

# EXPERIENCE 6 [robots=[32][31],send_mode=*,ir_power=2,clock=30Hz,msg_len=64]
y6 = [90,90,100,100,100,100,100,100,100,100,100,100,100,100,90,50,30,0,0,0]

# EXPERIENCE 7 [robots=[32][31],send_mode=*,ir_power=2,clock=60Hz,msg_len=64]
y7 = [100,100,100,100,100,100,100,100,100,100,100,100,100,90,90,10,10,0,0,0]

# EXPERIENCE 8 [robots=[32][31],send_mode=*,ir_power=2,clock=120Hz,msg_len=64]
y8 = [70,90,100,100,100,100,100,100,100,100,100,100,100,100,90,50,10,0,0,0]

# EXPERIENCE 9 [robots=[32][31],send_mode=*,ir_power=2,clock=180Hz,msg_len=64]
y9 = []

# EXPERIENCE 10 [robots=[32][31],send_mode=*,ir_power=2,clock=240Hz,msg_len=64]
y10 = []

# EXPERIENCE 11 [robots=[35][23],send_mode=*,ir_power=2,clock=30Hz,msg_len=64]
y11 = [70,100,100,100,100,100,100,100,100,100,100,100,100,100,70,10,0,0,0,0]

# EXPERIENCE 12 [robots=[35][23],send_mode=*,ir_power=2,clock=60Hz,msg_len=64]
y12 = [70,100,100,100,100,100,100,100,100,100,100,100,100,90,50,10,0,0,0,0]

# EXPERIENCE 13 [robots=[35][23],send_mode=*,ir_power=2,clock=120Hz,msg_len=64]
y13 = [70,100,100,100,100,100,100,100,100,100,100,100,100,90,70,30,10,0,0,0]

# EXPERIENCE 14 [robots=[35][23],send_mode=*,ir_power=2,clock=180Hz,msg_len=64]
y14 = [50,90,90,90,90,90,90,90,90,90,90,90,90,90,70,30,10,0,0,0]

# EXPERIENCE 15 [robots=[35][23],send_mode=*,ir_power=2,clock=240Hz,msg_len=64]
y15 = [10,10,50,50,50,50,50,50,50,50,50,50,50,50,30,10,0,0,0,0]




# EXPERIENCE 16 [robots=[6][4],send_mode=*,ir_power=1,clock=30Hz,msg_len=64]
y16 = [90,100,100,100,100,100,100,100,100,100,100,100,100,90,10,0,0,0, 0,0]

# EXPERIENCE 17 [robots=[6][4],send_mode=*,ir_power=3,clock=30Hz,msg_len=64]
y17 = [50,90,100,100,100,100,100,100,100,100,100,100,100,100,100,100,90,70,10,0]


# EXPERIENCE 18 [robots=[32][31],send_mode=*,ir_power=1,clock=30Hz,msg_len=64]
y18 = [70,100,100,100,100,100,100,100,100,100,100,100,100,90,30,10,0,0,0,0]

# EXPERIENCE 19 [robots=[32][31],send_mode=*,ir_power=3,clock=30Hz,msg_len=64]
y19 = [50,70,100,100,100,100,100,100,100,100,100,100,100,100,100,100,90,50,10,0]


# EXPERIENCE 20 [robots=[35][23],send_mode=*,ir_power=1,clock=30Hz,msg_len=64]
y20 = [100,100,100,100,100,100,100,100,100,100,100,90,70,30,10,0,0,0,0,0]

# EXPERIENCE 22 [robots=[35][23],send_mode=*,ir_power=3,clock=30Hz,msg_len=64]
y21 = [50,100,100,100,100,100,100,100,100,100,100,100,100,100,100,90,50,10,10,0]


# EXPERIENCE 22 [robots=[6][4],send_mode=*,ir_power=2,clock=30Hz,msg_len=1]
y22 = [70,100,100,100,100,100,100,100,100,100,100,100,100,100,90,70,30,10,0,0]

# EXPERIENCE 23 [robots=[6][4],send_mode=*,ir_power=2,clock=30Hz,msg_len=380]
y23 = [70,100,100,100,100,100,100,100,100,100,100,100,90,30,0,0,0,0,0,0]


# EXPERIENCE 24 [robots=[32][31],send_mode=*,ir_power=2,clock=30Hz,msg_len=1]
y24 = [90,90,100,100,100,100,100,100,100,100,100,100,100,100,90,70,30,10,0,0]

# EXPERIENCE 25 [robots=[32][31],send_mode=*,ir_power=2,clock=30Hz,msg_len=380]
y25 = [50,50,100,100,100,100,100,100,100,100,100,100,100,90,30,0,0,0,0,0]


# EXPERIENCE 26 [robots=[35][23],send_mode=*,ir_power=2,clock=30Hz,msg_len=1]
y26 = [90,100,100,100,100,100,100,100,100,100,100,100,100,100,90,90,50,30,0,0]

# EXPERIENCE 27 [robots=[35][23],send_mode=*,ir_power=2,clock=30Hz,msg_len=380]
y27 = [70,90,100,100,100,100,100,100,100,100,100,100,100,90,10,0,0,0,0,0]

#--------------------------------------------------------

# GRAPH 1 : OLD PROTOCOLE VS NEW PROTOCOLE
#plt.plot(x, y1_old, label="protocole=3.5MHz(beta1)")
#plt.plot(x, y1, label="protocole=3.5MHz(beta2)")
#plt.plot(x,y1_update, label="protocole=3.5MHz(final)")
#plt.title('Communication Protocols\nrobots=[6][4],send_mode=*,ir_power=2,clock=30Hz,msg_len=64')

# GRAPH 2 : FREQUENCIES ROBOTS=[6][4]
#plt.plot(x, y1, label="clock=30Hz")
#plt.plot(x, y2, label="clock=60Hz")
#plt.plot(x, y3, label="clock=120Hz")
#plt.plot(x, y4, label="clock=180Hz")
#plt.plot(x, y5, label="clock=240Hz")
#plt.title('Pairwise Communication 1D : Clock \nrobots=[6][4],send_mode=*,ir_power=2,msg_len=64')

# GRAPH 3 : FREQUENCIES ROBOTS=[31][32]
#plt.plot(x, y6, label="clock=30Hz")
#plt.plot(x, y7, label="clock=60Hz")
#plt.plot(x, y8, label="clock=120Hz")
#DO NOT UNCOMMENT plt.plot(x, y9, label="clock=180Hz")
#DO NOT UNCOMMENT plt.plot(x, y10, label="clock=240Hz")
#plt.title('Pairwise Communication 1D : Clock \nrobots=[31][32],send_mode=*,ir_power=2,msg_len=64')

# GRAPH 4 : FREQUENCIES ROBOTS=[35][23]
#plt.plot(x, y11, label="clock=30Hz")
#plt.plot(x, y12, label="clock=60Hz")
#plt.plot(x, y13, label="clock=120Hz")
#plt.plot(x, y14, label="clock=180Hz")
#plt.plot(x, y15, label="clock=240Hz")
#plt.title('Pairwise Communication 1D : Clock \nrobots=[35][23],send_mode=*,ir_power=2,msg_len=64')

# GRAPH 5 : FREQUENCIES clock=30Hz
#plt.plot(x, y1, label="robots=[6][4]")
#plt.plot(x, y6, label="robots=[31][32]")
#plt.plot(x, y11, label="robots=[35][23]")
#plt.title('Pairwise Communication 1D : Clock=30Hz \nsend_mode=*,ir_power=2,clock=30Hz,msg_len=64')

# GRAPH 6 : FREQUENCIES clock=60Hz
#plt.plot(x, y2, label="robots=[6][4]")
#plt.plot(x, y7, label="robots=[31][32]")
#plt.plot(x, y12, label="robots=[35][23]")
#plt.title('Pairwise Communication 1D : Clock=60Hz \nsend_mode=*,ir_power=2,clock=60Hz,msg_len=64')

# GRAPH 7 : FREQUENCIES clock=120Hz
#plt.plot(x, y3, label="robots=[6][4]")
#plt.plot(x, y8, label="robots=[31][32]")
#plt.plot(x, y13, label="robots=[35][23]")
#plt.title('Pairwise Communication 1D : Clock=120Hz \nsend_mode=*,ir_power=2,clock=120Hz,msg_len=64')

# GRAPH 8 : FREQUENCIES clock=180Hz
#plt.plot(x, y4, label="robots=[6][4]")
#DO NOT UNCOMMENTplt.plot(x, y9, label="robots=[31][32]")
#plt.plot(x, y14, label="robots=[35][23]")
#plt.title('Pairwise Communication 1D : Clock=180Hz \nsend_mode=*,ir_power=2,clock=180Hz,msg_len=64')

# GRAPH 9 : FREQUENCIES clock=240Hz
#plt.plot(x, y5, label="robots=[6][4]")
#DO NOT UNCOMMENTplt.plot(x, y9, label="robots=[31][32]")
#plt.plot(x, y15, label="robots=[35][23]")
#plt.title('Pairwise Communication 1D : Clock=240Hz \nsend_mode=*,ir_power=2,clock=240Hz,msg_len=64')

# GRAPH 10 : IRPOWER ROBOTS=[6][4]
#plt.plot(x, y16, label="ir_power=1")
#plt.plot(x, y1, label="ir_power=2")
#plt.plot(x, y17, label="ir_power=3")
#plt.title('Pairwise Communication 1D : IR Power \nrobots=[6][4],send_mode=*,clock=30Hz,msg_len=64')

# GRAPH 11 : IRPOWER ROBOTS=[31][32]
#plt.plot(x, y18, label="ir_power=1")
#plt.plot(x, y6, label="ir_power=2")
#plt.plot(x, y19, label="ir_power=3")
#plt.title('Pairwise Communication 1D : IR Power \nrobots=[31][32],send_mode=*,clock=30Hz,msg_len=64')

# GRAPH 12 : IRPOWER ROBOTS=[35][23]
#plt.plot(x, y20, label="ir_power=1")
#plt.plot(x, y11, label="ir_power=2")
#plt.plot(x, y21, label="ir_power=3")
#plt.title('Pairwise Communication 1D : IR Power \nrobots=[35][23],send_mode=*,clock=30Hz,msg_len=64')

# GRAPH 13 : IRPOWER ir_power=1
#plt.plot(x, y16, label="robots=[6][4]")
#plt.plot(x, y18, label="robots=[31][32]")
#plt.plot(x, y20, label="robots=[35][23]")
#plt.title('Pairwise Communication 1D : IR Power=1 \nsend_mode=*,ir_power=1,clock=30Hz,msg_len=64')

# GRAPH 14 : IRPOWER ir_power=2
#plt.plot(x, y1, label="robots=[6][4]")
#plt.plot(x, y6, label="robots=[31][32]")
#plt.plot(x, y11, label="robots=[35][23]")
#plt.title('Pairwise Communication 1D : IR Power=2 \nsend_mode=*,ir_power=2,clock=30Hz,msg_len=64')

# GRAPH 15 : IRPOWER ir_power=3
#plt.plot(x, y17, label="robots=[6][4]")
#plt.plot(x, y19, label="robots=[31][32]")
#plt.plot(x, y21, label="robots=[35][23]")
#plt.title('Pairwise Communication 1D : IR Power=3 \nsend_mode=*,ir_power=3,clock=30Hz,msg_len=64')

# GRAPH 16 : MSG LENGTH ROBOTS=[6][4]
#plt.plot(x, y22, label="msg_len=1")
#plt.plot(x, y1, label="msg_len=64")
#plt.plot(x, y23, label="msg_len=380")
#plt.title('Pairwise Communication 1D : Message Length \nrobots=[6][4],send_mode=*,ir_power=2,clock=30Hz')

# GRAPH 17 : MSG LENGTH ROBOTS=[31][32]
#plt.plot(x, y24, label="msg_len=1")
#plt.plot(x, y6, label="msg_len=64")
#plt.plot(x, y25, label="msg_len=380")
#plt.title('Pairwise Communication 1D : Message Length \nrobots=[31][32],send_mode=*,ir_power=2,clock=30Hz')

# GRAPH 18 : MSG LENGTH ROBOTS=[35][23]
#plt.plot(x, y26, label="msg_len=1")
#plt.plot(x, y11, label="msg_len=64")
#plt.plot(x, y27, label="msg_len=380")
#plt.title('Pairwise Communication 1D : Message Length \nrobots=[35][23],send_mode=*,ir_power=2,clock=30Hz')

# GRAPH 19 : MSG LENGTH msg_len=1
#plt.plot(x, y22, label="robots=[6][4]")
#plt.plot(x, y24, label="robots=[31][32]")
#plt.plot(x, y26, label="robots=[35][23]")
#plt.title('Pairwise Communication 1D : Payload=1byte \nsend_mode=*,ir_power=2,clock=30Hz,msg_len=1')

# GRAPH 20 : MSG LENGTH msg_len=64
#plt.plot(x, y1, label="robots=[6][4]")
#plt.plot(x, y6, label="robots=[31][32]")
#plt.plot(x, y11, label="robots=[35][23]")
#plt.title('PPairwise Communication 1D : Payload=64bytes \nsend_mode=*,ir_power=2,clock=30Hz,msg_len=64')

# GRAPH 21 : MSG LENGTH msg_len=380
#plt.plot(x, y23, label="robots=[6][4]")
#plt.plot(x, y25, label="robots=[31][32]")
#plt.plot(x, y27, label="robots=[35][23]")
#plt.title('Pairwise Communication 1D : Payload=380bytes \nsend_mode=*,ir_power=2,clock=30Hz,msg_len=380')



# Afficher le graphique

plt.xlim(0, 10)
plt.ylim(0, 110)
plt.xlabel('distance (centimeter)')
plt.ylabel('#messages received (over 100)')
plt.legend(loc='upper right')
plt.show()
