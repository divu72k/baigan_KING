import argparse
import requests

def send_req(url):
    try:
        response = requests.get(url)
        response.raise_for_status()
        print(f"request to {url} successful; status code: {response.status_code}")
    except requests.exceptions.RequestException as e:
        print(f"An error occurred while trying to make a request to {url}: \n{e}")

parser= argparse.ArgumentParser(description="automate http requests")
parser.add_argument("-u","--url", help="single url request")
parser.add_argument("-f","--file", help="file containing list of urls")
args= parser.parse_args()

if args.url:
    send_req(args.url)
elif args.file:
    with open(args.file, 'r') as f:
        urls=[line.strip() for line in f.readlines()]
        for i in urls:
            send_req(i)