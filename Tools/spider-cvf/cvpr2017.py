#!/usr/bin/env python
# coding=utf-8
import urllib
import urllib2
import re
def getHtml(url):
    page = urllib.urlopen(url)
    html = page.read()
    return html
def download_file(download_url,file_name):
    response = urllib2.urlopen(download_url)
    file = open(file_name, 'w')
    file.write(response.read())
    file.close()
    print("Completed")
save_path = '/home/cvpr2016/'
url = 'http://openaccess.thecvf.com/CVPR2017.py'
html = getHtml(url)
parttern = re.compile(r'\bcontent_cvpr_2017*paper\.pdf\b')
url_list = parttern.findall(html)
for url in url_list:
    name = url.split('/')[-1]
    file_name = save_path + name
    download_file(' http://openaccess.thecvf.com/content_cvpr_2017/papers/'+url,file_name)
