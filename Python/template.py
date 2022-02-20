from string import Template
from datetime import datetime
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
import smtplib


with open('static/template.html', 'r') as html:
    template = Template(html.read())
    date = datetime.now().strftime('%d/%m/%Y')
    body_msg = template.safe_substitute(name='William', date=date)
    
msg = MIMEMultipart()
msg['from'] = 'William Fernandes Dias'
msg['to'] = 'william.crazytests@gmail.com'
msg['subject'] = 'Test email sending with Python.'
body = MIMEText(body_msg, 'html')
msg.attach(body)

# Send with attachments
# with open('image.jpg', 'rb') as image:
#     img = MIMEImage(image.read())
#     msg.attach(img)

with smtplib.SMTP(host='smtp.gmail.com', port=587) as smtp:
    try:
        server = smtplib.SMTP_SSL('smtp.gmail.com', 465)
        server.ehlo()
        server.login('william.crazytests@gmail.com', 'QWERTY!@#')
        server.send_message(msg)
        print('Email sent successfully!')
    except Exception as error:
        print('Email was not sent...')
        print('Error: ', error)