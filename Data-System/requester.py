from fastapi import FastAPI
import subprocess
import time

app = FastAPI()

@app.get("/")

def login(loginorcreate: str, login: str, password: str, request: str, printwhat: str):
    if loginorcreate == "login":
        with open("logins.txt", "r+", encoding="utf-8") as logins:
            logins.read()
            achou = False
            for linha in logins:
                if not linha.strip():
                    continue
                else:
                    achou = True
                    login2, senha2 = linha.split("|")
                    if login2 == login and senha2 == password:
                        if request and printwhat or request or printwhat:
                            if not request:
                                return {"algo deu": "errado."}
                            if not printwhat:
                                with open("quest.txt", "w", encoding="utf-8") as request:
                                    request.write(f"{request}|null")
                            else:
                                with open("quest.txt", "w", encoding="utf-8") as request:
                                    request.write(f"{request}|{printwhat}")
                            comando = subprocess.run("make")
                            time.sleep(2)
                            with open("response.txt", "r", encoding="utf-8") as response:
                                response.read()
                                for linha in response:
                                    if not linha.split():
                                        return {"algo deu": "errado."}
                                    else:
                                        return linha
            if achou == False:
                return {"você não": "tem uma conta."}
