import requests
from bs4 import BeautifulSoup

url="https://google.com/"
response= requests.get(url)

if response.status_code==200:
    soup = BeautifulSoup(response.content, 'html.parser')
    links=soup.find_all('a') #finds all links of the pages in the website
    for link in links:
        print("Link : ",link.get('href'))
else:
    print("Error Code :",response.status_code)
    print("failed to retrieve the page")