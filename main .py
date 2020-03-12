import requests
import re
import json
import time
from ctypes import *
def getContent(url):
    r = requests.get(url)
    return r.content
def login(baseurl,email,password,s):
    content = s.get(url).content
    content = content.decode('utf-8')
    pattern = re.compile('.*?name=\'csrfmiddlewaretoken\' value=\'(.*?)\'.*?')
    match = pattern.findall(content)
    xsrf = match[0]
    login_data = {
        'csrfmiddlewaretoken': xsrf,
        'identification': email,
        'password': password,
    }
    s.post(baseurl,data=login_data)
session = requests.session()
url = "http://202.207.12.223:8000/accounts/signin/"
login(url,"0161122723","test",session)

dll=cdll.LoadLibrary('E:\VS保存文件\mydll\Debug\mydll.dll')
out=dll.Output

while 1:
    c=session.get('http://202.207.12.223:8000/join_game/',allow_redirects=False).headers['Location']
    c = re.sub("\D", "", c)
    while 1:
        a=session.get('http://202.207.12.223:8000/check_game/'+c).content.decode('utf-8')
        d=json.loads(a)
        if d['is_success']==False:
            if d['error']=='Game does not exist':
                break
        if d['winner']!='None':break
        if d['ready']=='False':
            time.sleep(4)
            continue
        if d['step']=='0':
            session.get('http://202.207.12.223:8000/play_game/' + c + '/?coord=hh')
            continue      
        if d['current_turn']=='0161122723':
            out.argtypes = [c_char_p]#参数
            out.restype = c_char_p#返回值
            print(bytes(d['board'],encoding='utf-8'))
            sb=d['board']
            nextstep=dll.Output((sb).encode('utf-8'))#下一步落点
            dll.reset()
            print(nextstep)           
            x=chr(nextstep[0])
            y=chr(nextstep[1])
            session.get('http://202.207.12.223:8000/play_game/'+c+'/?coord='+x+y)
            continue
        else:
            time.sleep(4)
            print("break")
            continue









