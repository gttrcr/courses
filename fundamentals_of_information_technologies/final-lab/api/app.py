from flask import Flask, request, jsonify
import sqlite3
import os

DB_PATH = "/data/app.db"

app = Flask(__name__, static_folder="static")


def get_db():
    conn = sqlite3.connect(DB_PATH)
    conn.row_factory = sqlite3.Row
    return conn


@app.route("/notes", methods=["GET"])
def get_notes():
    conn = get_db()
    cur = conn.cursor()
    cur.execute("SELECT id, text FROM notes")
    rows = cur.fetchall()
    conn.close()
    return jsonify([dict(r) for r in rows])


@app.route("/", methods=["GET"])
def index_page():
    return app.send_static_file("index.html")


@app.route("/delete", methods=["GET"])
def delete_page():
    return app.send_static_file("delete.html")


@app.route("/insert", methods=["GET"])
def insert_page():
    return app.send_static_file("insert.html")


@app.route("/update", methods=["GET"])
def update_page():
    return app.send_static_file("update.html")


@app.route("/notes", methods=["PUT"])
def put_notes():
    data = request.get_json()
    if not data or "text" not in data:
        return {"error": "Missing text"}, 400

    conn = get_db()
    cur = conn.cursor()
    cur.execute("INSERT INTO notes (text) VALUES (?)", (data["text"],))
    conn.commit()
    conn.close()
    return {"status": "ok"}


@app.route("/notes", methods=["POST"])
def post_notes():
    data = request.get_json()
    if not data or "old_text" not in data or "new_text" not in data:
        return {"error": "Missing text"}, 400

    conn = get_db()
    cur = conn.cursor()
    cur.execute("UPDATE notes SET text = ? WHERE text = ?", (data["new_text"], data["old_text"]))
    conn.commit()
    conn.close()
    return {"status": "ok"}


@app.route("/notes", methods=["DELETE"])
def delete_note():
    data = request.get_json()
    if not data or "text" not in data:
        return {"error": "Missing text"}, 400

    conn = get_db()
    cur = conn.cursor()
    cur.execute("DELETE FROM notes WHERE text = ?", (data["text"],))
    conn.commit()
    conn.close()
    return {"status": "ok"}


if __name__ == "__main__":
    # Crea DB e tabella se non esistono
    if not os.path.exists(DB_PATH):
        conn = sqlite3.connect(DB_PATH)
        conn.execute(
            """
            CREATE TABLE notes (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                text TEXT
            )
        """
        )
        conn.commit()
        conn.close()

    app.run(host="0.0.0.0", port=5000)
