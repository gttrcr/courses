from http.server import BaseHTTPRequestHandler, HTTPServer
import urllib.parse

HOST = "0.0.0.0"
PORT = 8080

class SimpleLoginHandler(BaseHTTPRequestHandler):

    def do_GET(self):
        if self.path == "/":
            self.send_response(200)
            self.send_header("Content-type", "text/html")
            self.end_headers()
            self.wfile.write(b"""
            <html>
                <body>
                    <h2>Login Page (HTTP - NOT SECURE)</h2>
                    <form method="POST" action="/login">
                        Username: <input type="text" name="username"><br><br>
                        Password: <input type="password" name="password"><br><br>
                        <input type="submit" value="Login">
                    </form>
                </body>
            </html>
            """)
        else:
            self.send_response(404)
            self.end_headers()

    def do_POST(self):
        if self.path == "/login":
            content_length = int(self.headers["Content-Length"])
            post_data = self.rfile.read(content_length)

            # Decodifica dati POST
            parsed_data = urllib.parse.parse_qs(post_data.decode())

            username = parsed_data.get("username", [""])[0]
            password = parsed_data.get("password", [""])[0]

            print(f"[!] Credenziali ricevute:")
            print(f"    Username: {username}")
            print(f"    Password: {password}")
            print("-" * 40)

            self.send_response(200)
            self.send_header("Content-type", "text/html")
            self.end_headers()
            self.wfile.write(b"""
            <html>
                <body>
                    <h3>Login ricevuto!</h3>
                    <p>(Questa pagina usa HTTP in chiaro)</p>
                    <a href="/">Torna indietro</a>
                </body>
            </html>
            """)
        else:
            self.send_response(404)
            self.end_headers()


if __name__ == "__main__":
    server = HTTPServer((HOST, PORT), SimpleLoginHandler)
    print(f"Server avviato su http://{HOST}:{PORT}")
    print("Premi CTRL+C per fermare il server.")
    server.serve_forever()

