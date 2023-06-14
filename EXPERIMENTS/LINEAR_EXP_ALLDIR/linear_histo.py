import matplotlib.pyplot as plt


x = [0, 0.5, 1,1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8, 9]

# EXPERIENCE 1 [IR=2,PROTOCOLE =3.5MhZ, FQ=30Hz, SENDER=4, RECEIVER=6, SIZEMSG=64octets]
y1 = [50, 70, 50, 30, 30,50,70,90,100,100,100,90,50,10,0,0,0,0]
#plt.plot(x, y1, label="senderID = 4\nreceiverID = 6\nsize=64octets")
#plt.title('Pogobot Communication 1D [IRPOWER=2,PROTOCOLE=3.5MhZ,\nF=ALLDIR,FQ=30Hz,SIZEMSG=64octets]')

# EXPERIENCE 2 [IR=2,PROTOCOLE =3.5MhZ, FQ=30Hz, SENDER=6, RECEIVER=4, SIZEMSG=64octets]
y2 = [10,50,50,30,30,50,70,90,90,100,100,90,90,70,30,0,0,0]
#plt.plot(x, y2, label="senderID = 6\nreceiverID = 4\nsize=64octets")
#plt.title('Pogobot Communication 1D [IRPOWER=2,PROTOCOLE=3.5MhZ,\nF=ALLDIR,FQ=30Hz,SIZEMSG=64octets]')

# EXPERIENCE 3 [IR=2,PROTOCOLE =3.5MhZ, FQ=60Hz, SENDER=4, RECEIVER=6, SIZEMSG=64octets]
y3 = [20, 70, 50, 30, 30, 50, 70, 90, 100, 100, 100,90,50,10,0,0,0,0]
#plt.plot(x, y3, label="senderID = 4\nreceiverID = 6")
#plt.title('Pogobot Communication 1D [IRPOWER=2,PROTOCOLE=3.5MhZ,\nF=ALLDIR,FQ=60Hz,SIZEMSG=64octets]')

# EXPERIENCE 4 [IR=2,PROTOCOLE =3.5MhZ, FQ=60Hz, SENDER=6, RECEIVER=4, SIZEMSG=64octets]
y4 = [10,50,50,30,30,50,70,90,100,100,100,100,90,70,30,0,0,0]
#plt.plot(x, y4, label="senderID = 6\nreceiverID = 4")
#plt.title('Pogobot Communication 1D [IRPOWER=2,PROTOCOLE=3.5MhZ,\nF=ALLDIR,FQ=60Hz,SIZEMSG=64octets]')

# EXPERIENCE 5 [IR=2,PROTOCOLE =3.5MhZ, FQ=120Hz, SENDER=4, RECEIVER=6, SIZEMSG=64octets]
y5 = [30,70,50,30,30,70,90,90,100,100,90,70,50,10,0,0,0,0]
#plt.plot(x, y5, label="senderID = 4\nreceiverID = 6")
#plt.title('Pogobot Communication 1D [IRPOWER=2,PROTOCOLE=3.5MhZ,\nF=ALLDIR,FQ=120Hz,SIZEMSG=64octets]')

# EXPERIENCE 6 [IR=2,PROTOCOLE =3.5MhZ, FQ=120Hz, SENDER=6, RECEIVER=4, SIZEMSG=64octets]
y6 = [10,30,30,30,30,50,70,90,90,100,100,100,90,70,30,0,0,0]
#plt.plot(x, y6, label="senderID = 6\nreceiverID = 4")
#plt.title('Pogobot Communication 1D [IRPOWER=2,PROTOCOLE=3.5MhZ,\nF=ALLDIR,FQ=120Hz,SIZEMSG=64octets]')

# EXPERIENCE 7 [IR=1,PROTOCOLE =3.5MhZ, FQ=30Hz, SENDER=4, RECEIVER=6, SIZEMSG=64octets]
y7 = [70,70,30,30,50,70,100,100,90,70,50,0,0,0,0,0,0,0]
#plt.plot(x, y7, label="senderID =4\nreceiverID = 6")
#plt.title('Pogobot Communication 1D [IRPOWER=1,PROTOCOLE=3.5MhZ,\nF=ALLDIR,FQ=30Hz,SIZEMSG=64octets]')

# EXPERIENCE 8 [IR=1,PROTOCOLE =3.5MhZ, FQ=30Hz, SENDER=6, RECEIVER=4, SIZEMSG=64octets]
y8 = [50,50,30,30,50,90,90,100,100,100,90,50,10,0,0,0,0,0]
#plt.plot(x, y8, label="senderID = 6\nreceiverID = 4")
#plt.title('Pogobot Communication 1D [IRPOWER=1,PROTOCOLE=3.5MhZ,\nF=ALLDIR,FQ=30Hz,SIZEMSG=64octets]')

# EXPERIENCE 9 [IR=3,PROTOCOLE =3.5MhZ, FQ=30Hz, SENDER=4, RECEIVER=6, SIZEMSG=64octets]
y9 = [10,50,70,50,50,30,50,70,70,95,100,100,90,90,50,10,0,0]
#plt.plot(x, y9, label="senderID =4\nreceiverID = 6")
#plt.title('Pogobot Communication 1D [IRPOWER=3,PROTOCOLE=3.5MhZ,\nF=ALLDIR,FQ=30Hz,SIZEMSG=64octets]')

# EXPERIENCE 10 [IR=3,PROTOCOLE =3.5MhZ, FQ=30Hz, SENDER=6, RECEIVER=4, SIZEMSG=64octets]
y10 = [0,10,70,50,30,30,50,70,70,90,90,100,100,100,90,70,50,0]
#plt.plot(x, y10, label="senderID = 6\nreceiverID = 4")
#plt.title('Pogobot Communication 1D [IRPOWER=3,PROTOCOLE=3.5MhZ,\nF=ALLDIR,FQ=30Hz,SIZEMSG=64octets]')

# EXPERIENCE 11 [IR=2,PROTOCOLE =3.5MhZ, FQ=30Hz, SENDER=4, RECEIVER=6, SIZEMSG=1octet]
y11 = [50,90,70,50,50,70,70,100,100,100,90,70,50,10,0,0,0,0]
plt.plot(x, y11, label="senderID =4\nreceiverID = 6\nsize=1")
#plt.title('Pogobot Communication 1D [IRPOWER=2,PROTOCOLE=3.5MhZ,\nF=ALLDIR,FQ=30Hz,SIZEMSG=1octet]')

# EXPERIENCE 12 [IR=2,PROTOCOLE =3.5MhZ, FQ=30Hz, SENDER=6, RECEIVER=4, SIZEMSG=1octet]
y12 = [10,30,50,50,50,50,70,90,100,100,100,100,90,70,50,10,0,0]
plt.plot(x, y12, label="senderID = 6\nreceiverID = 4\nsize=1")
#plt.title('Pogobot Communication 1D [IRPOWER=2,PROTOCOLE=3.5MhZ,\nF=ALLDIR,FQ=30Hz,SIZEMSG=1octet]')

# EXPERIENCE 13 [IR=2,PROTOCOLE =3.5MhZ, FQ=30Hz, SENDER=4, RECEIVER=6, SIZEMSG=200octet]
y13 = [30,50,50,30,30,50,70,90,100,100,90,90,50,0,0,0,0,0]
plt.plot(x, y13, label="senderID =4\nreceiverID = 6\nsize=200")
#plt.title('Pogobot Communication 1D [IRPOWER=2,PROTOCOLE=3.5MhZ,\nF=ALLDIR,FQ=30Hz,SIZEMSG=200octet]')

# EXPERIENCE 14 [IR=2,PROTOCOLE =3.5MhZ, FQ=30Hz, SENDER=6, RECEIVER=4, SIZEMSG=200octet]
y14 = [0,50,50,30,50,50,70,90,90,100,100,90,90,30,10,0,0,0]
plt.plot(x, y14, label="senderID = 6\nreceiverID = 4\nsize=200")
#plt.title('Pogobot Communication 1D [IRPOWER=2,PROTOCOLE=3.5MhZ,\nF=ALLDIR,FQ=30Hz,SIZEMSG=200octet]')

# EXPERIENCE 15 [IR=2,PROTOCOLE =3.5MhZ, FQ=30Hz, SENDER=4, RECEIVER=6, SIZEMSG=380octet]
y15 = [10,50,30,10,30,50,70,90,100,100,90,30,0,0,0,0,0,0]
plt.plot(x, y15, label="senderID =4\nreceiverID = 6\nsize=380")
#plt.title('Pogobot Communication 1D [IRPOWER=2,PROTOCOLE=3.5MhZ,\nF=ALLDIR,FQ=30Hz,SIZEMSG=380octet]')

# EXPERIENCE 16 [IR=2,PROTOCOLE =3.5MhZ, FQ=30Hz, SENDER=6, RECEIVER=4, SIZEMSG=380octet]
y16 = [0,50,50,10,30,50,70,90,100,100,90,90,30,0,0,0,0,0]
plt.plot(x, y16, label="senderID = 6\nreceiverID = 4\nsize=380")
plt.title('Pogobot Communication 1D [IRPOWER=2,PROTOCOLE=3.5MhZ,\nF=ALLDIR,FQ=30Hz]')





# Afficher le graphique

plt.xlim(0, 10)
plt.ylim(0, 110)
plt.xlabel('Distance (in cm)')
plt.ylabel('Reception succes rate (on 100msg)')
plt.legend(loc='upper right')
plt.show()