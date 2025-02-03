import json

dic = {
    "name": "Cindy",
    "rollno": 22,
    "phonenum": "0899144846"
}

jobj = json.dumps(dic, indent=4)

with open("ex1.json", "w") as output:
    output.write(jobj)