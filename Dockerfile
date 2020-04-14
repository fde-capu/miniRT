FROM debian:buster
RUN apt-get update && apt-get upgrade -y
COPY * /
CMD ["make", "&&", "./a.out"]
