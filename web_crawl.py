import os
import requests
from bs4 import BeautifulSoup
from urllib.parse import urljoin, urlparse

# Set the base URL to start crawling from
base_url = "https://example.com"

# Set the directory to store the crawled files
output_dir = "crawled_files"

# Create the output directory if it doesn't exist
if not os.path.exists(output_dir):
    os.makedirs(output_dir)

# Set the list of file extensions to filter
file_extensions = ["js", "php"]

# Function to get the file name from a URL
def get_file_name(url):
    parsed_url = urlparse(url)
    return os.path.basename(parsed_url.path)

# Function to download and store a file
def download_file(url, file_name):
    response = requests.get(url)
    with open(os.path.join(output_dir, file_name), "wb") as f:
        f.write(response.content)

# Function to recursively crawl a URL
def crawl_url(url):
    print(f"Crawling {url}...")
    response = requests.get(url)
    soup = BeautifulSoup(response.content, "html.parser")

    # Find all links on the page
    for link in soup.find_all("a", href=True):
        href = link["href"]
        if href.startswith("/"):
            href = urljoin(base_url, href)
        elif not href.startswith("http"):
            href = urljoin(url, href)

        # Check if the link is a file
        if urlparse(href).path.endswith((".js", ".php")):
            file_name = get_file_name(href)
            download_file(href, file_name)
            print(f"Downloaded {file_name}")
        else:
            # Recursively crawl the link
            crawl_url(href)

# Start crawling from the base URL
crawl_url(base_url)