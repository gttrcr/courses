FROM alpine:latest

RUN apk add --no-cache sqlite

WORKDIR /data

# Il DB verrà montato come volume
# Questo container non fa nulla, ospita solo lo stato
CMD ["tail", "-f", "/dev/null"]
