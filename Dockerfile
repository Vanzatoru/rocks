FROM gcc:latest
WORKDIR /usr/src/proiect
COPY proiect.c .
RUN gcc proiect.c -o proiect 
CMD ["./proiect"]