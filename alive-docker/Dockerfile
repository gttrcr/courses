FROM alpine
RUN apk add --no-cache bash
#RUN apk add --no-cache dos2unix
#RUN apk add --no-cache htop
COPY its_alive.sh /its_alive.sh
RUN chmod +x /its_alive.sh
CMD ["/its_alive.sh"]

