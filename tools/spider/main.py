#!/usr/bin/env python
# encoding:utf-8

import requests
import bs4
import time
import sys
import os

def getAllPages(soup):
    result = []
    table = soup.find("table", class_="exploit_list bootstrap-wrapper")
    tbody = table.find("tbody")
    trs = tbody.find_all("tr")
    for tr in trs:
        temp = tr.find("td", class_="description")
        link = temp.find("a")["href"]
        result.append(link)
    return result

headers = {
        "Host" : "www.exploit-db.com",
        "User-Agent" : "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:51.0) Gecko/20100101 Firefox/51.0",
        "Accept" : "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8",
        "Accept-Language" : "en-US,en;q=0.5",
        "Accept-Encoding" : "gzip, deflate, br",
        "Connection" : "keep-alive",
        "Upgrade-Insecure-Requests" : "1",
        "Pragma" : "no-cache",
        "Cache-Control" : "no-cache"
}

shellcode_types = [
            "Linux",
            "Lin_x86",
            "Lin_x86-64",
            "Windows",
            "Win_x86",
            "Win_x86-64",
            "Multiple",
            "Generator"
        ]

command = "git init"
os.system(command)

for shellcode_type in shellcode_types:
    os.makedirs("./cache/" + shellcode_type)
    url = "https://www.exploit-db.com/shellcode/?order_by=title&order=asc&p=" + shellcode_type
    response = requests.get(url, headers=headers)
    content = response.text.encode("UTF-8")
    soup = bs4.BeautifulSoup(content, "html.parser")
    
    links = getAllPages(soup)
    for link in links:
        print "=============================="
        print "Handling : " + link
        command = "python ./getItem.py " + link + " " + shellcode_type
        print command
        os.system(command)

