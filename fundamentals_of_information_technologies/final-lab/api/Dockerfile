FROM python:3.12-alpine

RUN apk add --no-cache sqlite sqlite-dev

WORKDIR /app

RUN pip install --upgrade pip
RUN pip install flask
RUN pip install -U flask-cors

COPY app.py .
COPY static/ ./static/

ENV FLASK_RUN_HOST=0.0.0.0
ENV FLASK_RUN_PORT=5000

EXPOSE 5000

CMD ["python3", "app.py"]
