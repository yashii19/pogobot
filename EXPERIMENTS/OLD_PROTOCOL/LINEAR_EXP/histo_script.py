import matplotlib.pyplot as plt


x = [0, 0.5, 1,1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8, 9]

# EXPERIENCE 1 [IR=2,PROTOCOLE =5MhZ, FQ=30Hz, SENDER=26, RECEIVER=24, SIZE=64octets]
y1 = [30, 70, 50, 30, 30, 50, 70, 90, 100, 100, 90, 80, 30, 10, 0, 0, 0, 0]
#plt.plot(x, y1, label="senderID = 26\nreceiverID = 24")
#plt.title('Pogobot Linear Communication 1D [IRPOWER=2,FONCT=ONE_DIR,\nPROTOCOLE=5MhZ,F=ALLFQ=30Hz,SIZE=64octets]')

# EXPERIENCE 2 [IR=2,PROTOCOLE =5MhZ, FQ=30Hz, SENDER=24, RECEIVER=26, SIZE=64octets]
y2 = [20, 70, 50, 30, 50, 70, 70, 90, 100, 100, 90, 90, 50, 10, 0, 0, 0, 0]
#plt.plot(x, y2, label="senderID = 24\nreceiverID = 26")
#plt.title('Pogobot Linear Communication 1D [IRPOWER=2,FONCT=ONE_DIR,\nPROTOCOLE=5MhZ,FQ=30Hz,SIZE=64octets]')

# EXPERIENCE 3 [IR=2, PROTOCOLE=3.5MhZ, FQ = 30Hz, SENDER=4, RECEIVER=6, SIZE=64octets]
y3 = [30, 70, 50, 30, 50, 70, 50, 90, 100, 100, 90, 70, 30, 10, 0, 0, 0, 0]
#plt.plot(x,  y3,  label="senderID = 4\nreceiverID = 6")
#plt.title('Pogobot Linear Communication 1D [IRPOWER=2,FONCT=ONE_DIR,\nPROTOCOLE=3.5MhZ,FQ=30Hz,SIZE=64octets]')

# EXPERIENCE 4 [IR=2, PROTOCOLE=3.5MhZ, FQ = 30Hz, SENDER=6, RECEIVER=4, SIZE=64octets]
y4 = [10, 70, 50, 30, 50, 70, 90, 90, 100, 100, 90, 90, 30, 10, 0, 0, 0, 0]
#plt.plot(x,  y4,  label="senderID = 6\nreceiverID = 4")
#plt.title('Pogobot Linear Communication 1D [IRPOWER=2,FONCT=ONE_DIR,\nPROTOCOLE=3.5MHz,FQ=30Hz,SIZE=64octets]')



# EXPERIENCE 5 [IR=2, PROTOCOLE=5MhZ, FQ = 60Hz, SENDER=26, RECEIVER=24, SIZE=64octets]
y5 = [30, 70, 70, 50, 40, 50, 70, 90, 100, 100, 90, 70, 50, 10, 0, 0, 0, 0]
#plt.plot(x,  y5,  label="senderID = 26\nreceiverID = 24")
#plt.title('Pogobot Linear Communication 1D [IRPOWER=2,FONCT=ONE_DIR,\nPROTOCOLE=5MHz,FQ=60Hz,SIZE=64octets]')

# EXPERIENCE 6 [IR=2, PROTOCOLE=5MhZ, FQ = 60Hz, SENDER=24, RECEIVER=26, SIZE=64octets]
y6 = [10, 70, 50, 30, 30, 50, 70, 90, 100, 100, 90, 90, 50, 10, 0, 0, 0, 0]
#plt.plot(x, y6, label="senderID = 24\nreceiverID = 26")
#plt.title('Pogobot Linear Communication 1D [IRPOWER=2,FONCT=ONE_DIR,\nPROTOCOLE=5MHz,FQ=60Hz,SIZE=64octets]')

# EXPERIENCE 7 [IR=2, PROTOCOLE=3.5MhZ, FQ = 60Hz, SENDER=4, RECEIVER=6, SIZE=64octets]
y7 = [30, 70, 50, 30, 50, 50, 70, 90, 100, 100, 90, 70, 30, 10, 0, 0, 0, 0]
#plt.plot(x, y7, label="senderID = 4\nreceiverID = 6")
#plt.title('Pogobot Linear Communication 1D [IRPOWER=2,FONCT=ONE_DIR,\nPROTOCOLE=3.5MHz,FQ=60Hz,SIZE=64octets]')

# EXPERIENCE 8 [IR=2, PROTOCOLE=3.MGhZ, FQ = 60Hz, SENDER=6, RECEIVER=4, SIZE=64octets]
y8 = [10, 50, 50, 30, 40, 70, 80, 90, 100, 100, 90, 80, 40, 10, 0, 0, 0, 0]
#plt.plot(x,  y8,  label="ssenderID = 6\nreceiverID = 4")
#plt.title('Pogobot Linear Communication 1D [IRPOWER=2,FONCT=ONE_DIR,\nPROTOCOLE=3.5MHz,FQ=60Hz,SIZE=64octets]')



# EXPERIENCE 9 [IR=2, PROTOCOLE=5MhZ, FQ = 120Hz, SENDER=26, RECEIVER=24, SIZE=64octets]
y9 = [30, 50, 70, 30, 50, 50, 70, 90, 100, 100, 100, 90, 30, 10, 0, 0, 0, 0]
#plt.plot(x,  y9,  label="senderID = 26\nreceiverID = 24")
#plt.title('Pogobot Linear Communication 1D [IRPOWER=2,FONCT=ONE_DIR,\nPROTOCOLE=5MHz,FQ=120Hz,SIZE=64octets]')

# EXPERIENCE 10 [IR=2, PROTOCOLE=5MhZ, FQ = 120Hz, SENDER=24, RECEIVER=26, SIZE=64octets]
y10 = [30, 70, 50 ,30 ,30 , 50, 70 ,90, 100, 100, 90, 90, 50, 10, 0, 0, 0, 0]
#plt.plot(x,  y10,  label="enderID = 24\nreceiverID = 26")
#plt.title('Pogobot Linear Communication 1D [IRPOWER=2,FONCT=ONE_DIR,\nPROTOCOLE=5MHz,FQ=120Hz,SIZE=64octets]')

# EXPERIENCE 11 [IR=2, PROTOCOLE=3.5MhZ, FQ = 120Hz, SENDER=4, RECEIVER=6, SIZE=64octets]
y11 = [30, 70, 50, 40, 70, 70, 90, 100, 100, 90, 70, 30, 10, 0, 0, 0, 0, 0]
#plt.plot(x,  y11,  label="senderID = 4\nreceiverID = 6")
#plt.title('Pogobot Linear Communication 1D [IRPOWER=2,FONCT=ONE_DIR,\nPROTOCOLE=3.5MHz,FQ=120Hz,SIZE=64octets]')

# EXPERIENCE 12 [IR=2, PROTOCOLE=3.5MhZ, FQ = 120Hz, SENDER=6, RECEIVER=4, SIZE=64octets]
y12 = [10, 70, 50, 30, 50, 70, 90, 100, 100, 100, 90, 60, 10, 0, 0, 0, 0, 0]
#plt.plot(x, y12,  label="senderID = 6\nreceiverID = 4")
#plt.title('Pogobot Linear Communication 1D [IRPOWER=2,FONCT=ONE_DIR,\nPROTOCOLE=3.5MHz,FQ=120Hz,SIZE=64octets]')



# EXPERIENCE 13 [IR=1,PROTOCOLE =5MhZ, FQ=30Hz, SENDER=26, RECEIVER=24, SIZE=64octets]
y13 = [70,70,50,50,50,70,90,100,100,90,50,0,0,0,0,0,0,0]
#plt.plot(x, y13, label="senderID = 26\nreceiverID = 24")
#plt.title('Pogobot Linear Communication 1D [IRPOWER=1,FONCT=ONE_DIR,\nPROTOCOLE=5MHz,FQ=30Hz,SIZE=64octets]')

# EXPERIENCE 14 [IR=1,PROTOCOLE =5MhZ, FQ=30Hz, SENDER=24, RECEIVER=26, SIZE=64octets]
y14 = [70,70,50,50,50,70,90,100,100,90,50,0,0,0,0,0,0,0]
#plt.plot(x, y14, label="senderID = 24\nreceiverID = 26")
#plt.title('Pogobot Linear Communication 1D [IRPOWER=1,FONCT=ONE_DIR,\nPROTOCOLE=5MHz,FQ=30Hz,SIZE=64octets]')

# EXPERIENCE 15 [IR=1, PROTOCOLE=3.5MhZ, FQ = 30Hz, SENDER=4, RECEIVER=6, SIZE=64octets]
y15 = [70,30,30,50,70,70,100,90,100,90,50,0,0,0,0,0,0,0]
#plt.plot(x,  y15,  label="senderID = 4\nreceiverID = 6")
#plt.title('Pogobot Linear Communication 1D [IRPOWER=1,FONCT=ONE_DIR,\nPROTOCOLE=3.5MHz,FQ=30Hz,SIZE=64octets]')

# EXPERIENCE 16 [IR=1, PROTOCOLE=3.5MhZ, FQ = 30Hz, SENDER=6, RECEIVER=4, SIZE=64octets]
y16 = [10,50,30,50,70,90,100,100,100,90,30,0,0,0,0,0,0,0]
#plt.plot(x,  y16,  label="senderID = 6\nreceiverID = 4")
#plt.title('Pogobot Linear Communication 1D [IRPOWER=1,FONCT=ONE_DIR,\nPROTOCOLE=3.5MHz,FQ=30Hz,SIZE=64octets]')



# EXPERIENCE 17 [IR=3, PROTOCOLE=5MhZ, FQ = 30Hz, SENDER=26, RECEIVER=24, SIZE=64octets]
y17 = [0,50,70,50,30,30,50,70,70,90,100,100,100,90,50,10,0,0]
#plt.plot(x,  y17,  label="senderID = 26\nreceiverID = 24")
#plt.title('Pogobot Linear Communication 1D [IRPOWER=3,FONCT=ONE_DIR,\nPROTOCOLE=5MHz,FQ=30Hz,SIZE=64octets]')


# EXPERIENCE 18 [IR=3, PROTOCOLE=5MhZ, FQ = 30Hz, SENDER=24, RECEIVER=26, SIZE=64octets]
y18 = [0,70,70,50,30,30,50,70,70,90,100,100,90,90,50,30,0,0]
#plt.plot(x, y18, label="senderID = 24\nreceiverID = 26")
#plt.title('Pogobot Linear Communication 1D [IRPOWER=3,FONCT=ONE_DIR,\nPROTOCOLE=5MHz,FQ=30Hz,SIZE=64octets]')


# EXPERIENCE 19 [IR=3, PROTOCOLE=3.5MhZ, FQ = 30Hz, SENDER=4, RECEIVER=6, SIZE=64octets]
y19 = [30,70,70,50,30,30,50,70,90,90,100,100,90,90,50,10,0,0]
#plt.plot(x, y19, label="senderID = 4\nreceiverID = 6")
#plt.title('Pogobot Linear Communication 1D [IRPOWER=3,FONCT=ONE_DIR,\nPROTOCOLE=3.5MHz,FQ=30Hz,SIZE=64octets]')

# EXPERIENCE 20 [IR=3, PROTOCOLE=3.5MhZ, FQ = 30Hz, SENDER=6, RECEIVER=4, SIZE=64octets]
y20 = [0,30,70,50,30,50,50,70,90,100,100,100,100,90,50,10,0,0]
#plt.plot(x,  y20,  label="ssenderID = 6\nreceiverID = 4")
#plt.title('Pogobot Linear Communication 1D [IRPOWER=3,FONCT=ONE_DIR,\nPROTOCOLE=3.5MHz,FQ=30Hz,SIZE=64octets]')



# EXPERIENCE 21 [IR=2,PROTOCOLE =5MhZ, FQ=30Hz, SENDER=26, RECEIVER=24, SIZE=1octets]
y21 = [30, 70, 70, 50, 50, 50, 70, 90,100,100,100,100,90,50,10,0,0,0]
#plt.plot(x,  y21,  label="senderID = 26\nreceiverID = 24")
#plt.title('Pogobot Linear Communication 1D [IRPOWER=2,FONCT=ONE_DIR,\nPROTOCOLE=5MHz,FQ=30Hz,SIZE=1octets]')


# EXPERIENCE 22 [IR=2,PROTOCOLE =5MhZ, FQ=30Hz, SENDER=24, RECEIVER=26, SIZE=1octets]

# EXPERIENCE 23 [IR=2,PROTOCOLE =3.5MhZ, FQ=30Hz, SENDER=6, RECEIVER=4, SIZE=1octets]
y23 = [10, 70, 50 ,50 ,50 ,70 ,70 ,90 ,100, 100, 100, 90, 50, 10, 0,0, 0, 0]
#plt.plot(x,  y23,  label="senderID = 6\nreceiverID = 4")
#plt.title('Pogobot Linear Communication 1D [IRPOWER=2,FONCT=ONE_DIR,\nPROTOCOLE=3.5MHz,FQ=30Hz,SIZE=1octets]')

# EXPERIENCE 24 [IR=2,PROTOCOLE =3.5MhZ, FQ=30Hz, SENDER=4, RECEIVER=26, SIZE=1octets]
y24 = [10,50,50,50,50,70,90,90,100,100,100,90,50,10,0,0,0,0]
#plt.plot(x,  y24,  label="senderID = 4\nreceiverID = 6")
#plt.title('Pogobot Linear Communication 1D [IRPOWER=2,FONCT=ONE_DIR,\nPROTOCOLE=3.5MHz,FQ=30Hz,SIZE=1octets]')



# EXPERIENCE 25 [IR=2,PROTOCOLE =5MhZ, FQ=30Hz, SENDER=26, RECEIVER=24, SIZE=380octets]
y25 = [10,50,50,50,50,70,90,90,100,100,100,90,50,10,0,0,0,0]
plt.plot(x,  y25,  label="senderID = 26\nreceiverID = 24")
plt.title('Pogobot Linear Communication 1D [IRPOWER=2,FONCT=ONE_DIR,\nPROTOCOLE=3.5MHz,FQ=30Hz,SIZE=1octets]')

# EXPERIENCE 26 [IR=2,PROTOCOLE =3.5GhZ, FQ=30Hz, SENDER=4, RECEIVER=26, SIZE=380octets]


# EXPERIENCE 27 [IR=2,PROTOCOLE =3.5GhZ, FQ=30Hz, SENDER=4, RECEIVER=6, SIZE=380octets]
y27 = [10,50,50,50,50,70,90,90,100,100,100,90,50,10,0,0,0,0]
#plt.plot(x,  y27,  label="senderID = 4\nreceiverID = 6")
#plt.title('Pogobot Linear Communication 1D [IRPOWER=2,FONCT=ONE_DIR,\nPROTOCOLE=3.5MHz,FQ=30Hz,SIZE=1octets]')

# EXPERIENCE 28 [IR=2,PROTOCOLE =3.5GhZ, FQ=30Hz, SENDER=6, RECEIVER=4, SIZE=380octets]






# Afficher le graphique

plt.xlim(0, 10)
plt.ylim(0, 110)
plt.xlabel('Distance (in cm)')
plt.ylabel('Reception succes rate (on 100msg)')
plt.legend(loc='upper right')
plt.show()