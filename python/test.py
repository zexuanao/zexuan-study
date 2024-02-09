import requests
from bs4 import BeautifulSoup
head={ "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/121.0.0.0 Safari/537.36 Edg/121.0.0.0"}
response=requests.get("https://movie.douban.com/chart", headers=head)
html=response.text
soup=BeautifulSoup(html,"html.parser")
all_titles=soup.findAll("div",attrs={"class":"pl2"})
for title in all_titles:
    all_links=title.findAll("a")
    for link in all_links:
        text = link.get_text(strip=True)
        slash_index = text.find('/')
        first_chinese_text = text[:slash_index].strip()
        print(first_chinese_text)
        
        
        #keys=link.findAll("span",attrs={"style":"font-size:13px;"})
        #for key in keys:
        #    print(key.string)