# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    send.py                                          .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/04/03 15:25:49 by kcabus       #+#   ##    ##    #+#        #
#    Updated: 2018/04/03 17:58:31 by kcabus      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

import getpass
import sys
import smtplib
from email.MIMEMultipart import MIMEMultipart
from email.MIMEText import MIMEText

a = input("Quel est votre fournisseur\n1 - Gmail\n2 - Hotmail\n3 - Laposte\nLes autres fournisseur ne sont pas suportes\n")
if a == 1:
    server = smtplib.SMTP("smtp.gmail.com", 587)
elif a == 2:
    server = smtplib.SMTP("smtp.live.com", 587)
elif a == 3:
    server = smtplib.SMTP("smtp.laposte.fr", 587)
else:
    sys.exit(0)

msg = MIMEMultipart()
msg['From'] = raw_input("Votre adresse mail :\n")
mdp = getpass.getpass("Entrez votre mot de passe : ")
msg['To'] = raw_input("Mail du destinataire :\n")
msg['Subject'] = raw_input("Objet du mail :\n")

corps = raw_input("Tapez votre message :\n")
msg.attach(MIMEText(corps, 'plain'))

text = msg.as_string()

server.starttls()
server.login(msg['From'], mdp)
server.sendmail(msg['From'], msg['To'], text)
server.quit()
