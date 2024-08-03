import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
import os

def sendEmail(msg, rec):
    sender = "revaluations.properties@gmail.com"
    my_password = r"ututgxeicnivajde"
    content = f'<html><body><h4>{msg}</h4></body></html>'
    msg = MIMEMultipart('alternative')
    msg['Subject'] = "Revaluations"
    msg['From'] = sender
    msg['To'] = rec
    part2 = MIMEText(content, 'html')

    msg.attach(part2)

    s = smtplib.SMTP_SSL('smtp.gmail.com')

    s.login(sender, my_password)

    s.sendmail(sender, receivers, msg.as_string())
    s.quit()

def readReceivers():
    file1 = open(os.getcwd()+"\\python-email\\receiver.txt", 'r')
    receivers = ""
    count = 0
    
    while True:
        count += 1
    
        # Get next line from file
        line = file1.readline()
    
        # if line is empty
        # end of file is reached
        if not line:
            break
        if receivers == "":
            receivers = line
        else:
            receivers = receivers + "," + line
    file1.close()
    receivers = receivers.replace('\n','')
    return receivers

def readContent():
    f = open(os.getcwd()+"\\python-email\\content.txt", 'r')
    data = f.read()
    f.close()
    return data
    

if __name__ == "__main__":
    receivers = readReceivers()
    msg = readContent()
    # print(receivers)
    sendEmail(msg, receivers)
