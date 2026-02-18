from http.server import HTTPServer, BaseHTTPRequestHandler
import ssl
import urllib.parse

HOST = "0.0.0.0"
PORT = 4443


class SecureLoginHandler(BaseHTTPRequestHandler):

    def do_GET(self):
        if self.path == "/":
            self.send_response(200)
            self.send_header("Content-type", "text/html")
            self.end_headers()
            self.wfile.write(
                b"""
            <html>
                <body>
                    <h2>Login Page (HTTPS - SECURE)</h2>
                    <form method="POST" action="/login">
                        Username: <input type="text" name="username"><br><br>
                        Password: <input type="password" name="password"><br><br>
                        <input type="submit" value="Login">
                    </form>
                </body>
            </html>
            """
            )
        else:
            self.send_response(404)
            self.end_headers()

    def do_POST(self):
        if self.path == "/login":
            content_length = int(self.headers["Content-Length"])
            post_data = self.rfile.read(content_length)

            parsed_data = urllib.parse.parse_qs(post_data.decode())
            username = parsed_data.get("username", [""])[0]
            password = parsed_data.get("password", [""])[0]

            print("[!] Credenziali ricevute via HTTPS")
            print(f"    Username: {username}")
            print(f"    Password: {password}")
            print("-" * 40)

            self.send_response(200)
            self.send_header("Content-type", "text/html")
            self.end_headers()
            self.wfile.write(
                b"""
            <html>
                <body>
                    <h3>Login ricevuto in modo cifrato!</h3>
                    <a href="/">Torna indietro</a>
                </body>
            </html>
            """
            )
        else:
            self.send_response(404)
            self.end_headers()


if __name__ == "__main__":
    httpd = HTTPServer((HOST, PORT), SecureLoginHandler)

    # Creazione contesto TLS moderno
    context = ssl.SSLContext(ssl.PROTOCOL_TLS_SERVER)
    context.load_cert_chain(certfile="cert.pem", keyfile="key.pem")

    # Wrappiamo il socket del server
    httpd.socket = context.wrap_socket(httpd.socket, server_side=True)

    print(f"Server HTTPS avviato su https://{HOST}:{PORT}")
    print("Premi CTRL+C per fermare il server.")

    httpd.serve_forever()
